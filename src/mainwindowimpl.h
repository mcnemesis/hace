#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QMainWindow>
#include "ui_mainwindow.h"
//
class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	
	//Longest Common String solver
	int LongestCommonSubstring(QString, QString);
private slots:
	void count();
	void stopTimer();
	void pauseGame();
	void startGame();
	void process();
	void playNext();
	
	//init interpreter
	void init_interpreter();
	void readInterpreter();
	void interpreterStarted();
	void interpreterError();
	
	int get_code_score(QString, QString);
	int get_output_score(QString, QString);
	void loadChallenges();
	void playChallenge(int i);
	
	void printToOutput(QString);
	void printToCode(QString);
	void printToChallenge(QString);
};
#endif






