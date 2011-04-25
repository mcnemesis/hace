#include "mainwindowimpl.h"
//
#include <QTimer>
#include <QTime>
#include <QProcess>
#include <QTextDocument>
#include <cmath>
#include <QVector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

//for yaml
#include "yaml-cpp/yaml.h"


//time stuff
QTimer * timer;
QTime game_time = QTime(0,0,0);
bool game_paused = false;
bool game_started = false;

//points stuff
int game_points = 0;

QProcess * interpreter;
QStringList arguments;
QString program = "python";

int CODE_SCORE_PERCENT = 70;
int OUTPUT_SCORE_PERCENT = 30;

int code_similarity_score = 0;
double code_length = 0;
int outpur_similarity_score = 0;
double output_length = 0;

int challenge_number = 0;

//a struct describing our challenge data nodes
struct Challenge
{
    QString real_code;
    QString name;
    QString description;
    QString macaronni_code;
    QString desired_output;
    int Level;
};

typedef struct Challenge Challenge;

//challenges : a vector of challenges
QVector<Challenge> challenges;

//over-loading the >> operator to load fields into our Challenge
//from a yaml node
void operator >> (const YAML::Node& node, Challenge& challenge)
{
    std::string desired, macaroni, realc, name, desc;

    node["Level"] >> challenge.Level;
    node["Output"] >> desired;
    node["Macarroni"] >> macaroni;
    node["RealCode"] >> realc;
    node["Name"] >> name;
    node["Description"] >> desc;

    challenge.desired_output = QString(desired.c_str());
    challenge.macaronni_code = QString(macaroni.c_str());
    challenge.real_code = QString(realc.c_str());
    challenge.name = QString(name.c_str());
    challenge.description = QString(desc.c_str());
}

/*load challenge objects from the given challenges yaml file*/
void loadFileChallenges(const char * challenges_file)
{
    std::ifstream fin(challenges_file);
    YAML::Parser parser(fin);
    YAML::Node doc;

    parser.GetNextDocument(doc);
    for (unsigned i=0;i<doc.size();i++)
    {
        Challenge challenge;
        doc[i] >> challenge;
        challenges.append(challenge);
    }

    std::cout << "Loaded " << doc.size() << " Challenges from " << challenges_file << std::endl;
}


MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f)
        : QMainWindow(parent, f)
{
    setupUi(this);
    //create our timer
    timer = new QTimer(this);

    //connect event-callbacks
    connect(timer,SIGNAL(timeout()),this,SLOT(count()));
    connect(btnStop,SIGNAL(clicked()),this,SLOT(stopTimer()));
    connect(btnPause,SIGNAL(clicked()),this,SLOT(pauseGame()));
    connect(btnStart,SIGNAL(clicked()),this,SLOT(startGame()));
    connect(btnProcess,SIGNAL(clicked()),this,SLOT(process()));
    connect(btnNext,SIGNAL(clicked()),this,SLOT(playNext()));

    btnNext->hide();

    loadChallenges();
}
//

/*shuffle the contents of the challenges vector*/
void shuffleChallenges(QVector<Challenge> &cvector)
{
	/* initialize random seed: */
	srand ( time(NULL) );
	//std::cout << "Challenges in shuflle : " << cvector.size() << std::endl;
	int size = cvector.size();
	for(int i =  0; i < size; i++)
	{
		int ra = (rand() % size); //a not so random number between 0 and i inclusive
		Challenge temp = cvector[ra];
		cvector[ra] = cvector[i];
		cvector[i] = temp;	
		//std::cout << "shuffling " << i << std::endl;	
	}
}

	void MainWindowImpl::printToOutput(QString str)
	{
		txtOutput->setDocument(new QTextDocument(str,this));
		QPalette pal;
		pal.setColor(QPalette::Window,QColor::fromRgb(0,0,0));
		pal.setColor(QPalette::Text, QColor::fromRgb(171,171,0));
		txtOutput->setPalette(pal);
		txtOutput->setFont(QFont("FreeMono"));
		txtOutput->document()->setDefaultFont(QFont("FreeMono"));
	}
	void MainWindowImpl::printToCode(QString str)
	{
		txtCode->setDocument(new QTextDocument(str,this));
		QPalette pal;
		pal.setColor(QPalette::Window,QColor::fromRgb(0,0,0));
		pal.setColor(QPalette::Text, QColor::fromRgb(51,188,24));
		txtCode->setPalette(pal);
		txtCode->setFont(QFont("FreeMono"));
		txtCode->document()->setDefaultFont(QFont("FreeMono"));
	}
	void MainWindowImpl::printToChallenge(QString str)
	{
		txtChallenge->setDocument(new QTextDocument(str,this));
		QPalette pal;
		pal.setColor(QPalette::Window,QColor::fromRgb(0,0,0));
		//pal.setColor(QPalette::WindowText,QColor::fromRgb(0,0,0));
		pal.setColor(QPalette::Text, QColor::fromRgb(24,217,214));
		txtChallenge->setPalette(pal);
		txtChallenge->setFont(QFont("FreeMono"));
		txtChallenge->document()->setDefaultFont(QFont("FreeMono"));
	}

void MainWindowImpl::loadChallenges()
{
    /*QString realcode = "l = lambda x : x**2\nprint [l(x) for x in range(10)]";
    QString macarroni = "ladmba ** print \n l=(x) for range(x) [ 2 ] : ";
    QString output = "[0, 1, 4, 9, 16, 25, 36, 49, 64, 81]";
    int level = 1;

    Challenge chal;

    chal.Level = level;
    chal.desired_output = output;
    chal.macaronni_code = macarroni;
    chal.real_code = realcode;

    challenges.append(chal);*/

    loadFileChallenges(std::string("challenges.yaml").c_str());
    shuffleChallenges(challenges);
}

/*get the portion of the current session's score based on the code's similarity to the correct/ original*/
int MainWindowImpl::get_code_score(QString user_code, QString real_code)
{
    return 	(int)floor(((LongestCommonSubstring(user_code,real_code) * 1.0) / real_code.length()) * CODE_SCORE_PERCENT);
}

/*get the portion of the current session's score based on the code's output*/
int MainWindowImpl::get_output_score(QString user_ouput, QString real_output)
{
    return 	(int)floor(((LongestCommonSubstring(user_ouput,real_output) * 1.0) / real_output.length()) * OUTPUT_SCORE_PERCENT);
}

//initialize an interpreter for processing player's code
void MainWindowImpl::init_interpreter()
{
    interpreter = new QProcess(this);
    arguments = QStringList();

    connect( interpreter, SIGNAL(readyReadStandardOutput()),this, SLOT(readInterpreter()) );
    connect( interpreter, SIGNAL(readyReadStandardError()),this, SLOT(interpreterError()) );
    connect( interpreter, SIGNAL(started()),this, SLOT(interpreterStarted()) );
    
    

    interpreter->start(program,arguments);
}

/*send the current player's code to the interpreter*/
void MainWindowImpl::process()
{
    if (!game_started || game_paused) return;

    init_interpreter();

    QString code = txtCode->toPlainText();
    interpreter->write(code.toAscii(),code.length());
    interpreter->closeWriteChannel();
    printToOutput("sent code to interpreter...");

}

//when an error occurs while interacting with the interpreter
void MainWindowImpl::interpreterError()
{
    printToOutput("Hace! interpreter encountered an error\r\nPossibly caused by a bug in yo hack...");
}

//when the interpreter starts successfully
void MainWindowImpl::interpreterStarted()
{
    printToOutput("Hace! interpreter is now running");
}

//when the interpreter's ouput is ready for reading
void MainWindowImpl::readInterpreter()
{
    QString user_output = interpreter->readAllStandardOutput();
    printToOutput(user_output);

    QString user_code = txtCode->toPlainText();
    Challenge chal = challenges[challenge_number];

    int current_points = get_code_score(user_code,chal.real_code) + get_output_score(user_output,chal.desired_output);

    lcdPoints->display(game_points + current_points);

    if (	current_points >= 70)
        btnNext->show();
    else
        btnNext->hide();

    interpreter->close();

}

//start the game
void MainWindowImpl::startGame()
{
    if (game_started) return;

    //clear the input box
    txtCode->clear();
    printToCode(""); //to ensure our color settings get applied

    //get first challenge
    if (challenges.size() > 0)
    {
        playChallenge(challenge_number);
        game_started = true;
        txtCode->setFocus();
        timer->start(1000);
    }
    else
    {
        printToChallenge("Sorry! No Challenges to Hace!");
        txtChallenge->setFont(QFont("FreeMono"));
    }

}

/*attempt to load the next challenge in the list*/
void MainWindowImpl::playNext()
{
    game_points = lcdPoints->value();

    lcdPoints->display(game_points);

    txtCode->clear();
    printToCode(""); //to ensure our color settings get applied
    txtOutput->clear();
    txtChallenge->clear();

    QString str = QString("\r\n\r\nmaking progress: u currently have ||").append(QString::number(game_points)).append("  :: Rep Power||")
                  .append("\r\n\r\rYou are progressing on to challenge ").append(QString::number(challenge_number + 2));

    printToOutput(str);

    if (challenge_number < challenges.size())
        challenge_number += 1;

    playChallenge(challenge_number);
}

/*attempt to load the challenge at the given index from the challenges collection*/
void MainWindowImpl::playChallenge(int i)
{
	btnNext->hide();
	
    //get challenge
    if (i < challenges.size())
    {
        Challenge chal = challenges[i];

        QString str = QString("Hace! is ON :: ").append(chal.name).
                      append(QString("\r\n\r\n---- Crack this code -----\r\n\r\n"));
        str.append(chal.macaronni_code).append("\r\n\r\n---- To Obtain -----\r\n\r\n").append(chal.desired_output);
        str.append(QString("\r\n\r\n~~~ </> </> what? </> </> ~~~\r\n")).append(chal.description);

        printToChallenge(str);

        txtChallenge->setFont(QFont("FreeMono"));

        lcdLevel->display(chal.Level);
    }
    else
    {
        printToChallenge("Sorry! No Challenges to Hace!");
        txtChallenge->setFont(QFont("FreeMono"));
    }
}

/*will keep incrementing and displaying the amount of time into the game*/
void MainWindowImpl::count()
{
    if (!game_started || game_paused) return;

    game_time = game_time.addSecs(1);
    GameTime->setTime(game_time);
}

/*stop the timer*/
void MainWindowImpl::stopTimer()
{
    if (!game_started) return;

    timer->stop();
}

/*pause the game*/
void MainWindowImpl::pauseGame()
{
    if (!game_started) return;

    if (!game_paused)
    {
        timer->stop();
        btnPause->setText("&Resume");
        game_paused = true;
    }
    else
    {
        timer->start(1000);
        btnPause->setText("&Pause");
        game_paused = false;
    }
}

//Get the longest common substring
int MainWindowImpl::LongestCommonSubstring(QString str1, QString str2)
{
    if (str1.isEmpty() || str2.isEmpty())
        return 0;

    int *curr = new int [str2.length()];
    int *prev = new int [str2.length()];
    int *swap = NULL;
    int maxSubstr = 0;

    for (int i = 0; i<str1.length(); ++i)
    {
        for (int j = 0; j<str2.length(); ++j)
        {
            if (str1[i] != str2[j])
            {
                curr[j] = 0;
            }
            else
            {
                if (i == 0 || j == 0)
                {
                    curr[j] = 1;
                }
                else
                {
                    curr[j] = 1 + prev[j-1];
                }
                //The next if can be replaced with:
                //maxSubstr = max(maxSubstr, curr[j]);
                //(You need algorithm.h library for using max())
                maxSubstr = (maxSubstr < curr[j]) ? curr[j] : maxSubstr;
            }
        }
        swap=curr;
        curr=prev;
        prev=swap;
    }
    delete [] curr;
    delete [] prev;
    return maxSubstr;
}



