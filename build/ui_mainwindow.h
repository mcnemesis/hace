/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionQuit;
    QAction *actionLanguage;
    QAction *actionHow_to_Hace;
    QAction *actionAbout;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnNew;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QTextEdit *txtOutput;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QTimeEdit *GameTime;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QLCDNumber *lcdPoints;
    QLabel *lblStatus;
    QTextEdit *txtCode;
    QPushButton *btnProcess;
    QPushButton *btnNext;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLCDNumber *lcdLevel;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *txtChallenge;
    QMenuBar *menubar;
    QMenu *menuHace;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(848, 579);
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Mono L"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionLanguage = new QAction(MainWindow);
        actionLanguage->setObjectName(QString::fromUtf8("actionLanguage"));
        actionHow_to_Hace = new QAction(MainWindow);
        actionHow_to_Hace->setObjectName(QString::fromUtf8("actionHow_to_Hace"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btnNew = new QPushButton(centralwidget);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));

        verticalLayout_2->addWidget(btnNew);

        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));

        verticalLayout_2->addWidget(btnStart);

        btnPause = new QPushButton(centralwidget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));

        verticalLayout_2->addWidget(btnPause);

        btnStop = new QPushButton(centralwidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));

        verticalLayout_2->addWidget(btnStop);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        txtOutput = new QTextEdit(centralwidget);
        txtOutput->setObjectName(QString::fromUtf8("txtOutput"));
        QPalette palette;
        QBrush brush(QColor(171, 171, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(83, 82, 81, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        txtOutput->setPalette(palette);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        txtOutput->setFont(font1);
        txtOutput->setReadOnly(true);

        verticalLayout_3->addWidget(txtOutput);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        GameTime = new QTimeEdit(centralwidget);
        GameTime->setObjectName(QString::fromUtf8("GameTime"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        GameTime->setFont(font2);
        GameTime->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        GameTime->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, GameTime);


        horizontalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        lcdPoints = new QLCDNumber(centralwidget);
        lcdPoints->setObjectName(QString::fromUtf8("lcdPoints"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcdPoints->sizePolicy().hasHeightForWidth());
        lcdPoints->setSizePolicy(sizePolicy);
        lcdPoints->setBaseSize(QSize(0, 0));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        lcdPoints->setFont(font3);
        lcdPoints->setFrameShape(QFrame::WinPanel);
        lcdPoints->setNumDigits(6);
        lcdPoints->setSegmentStyle(QLCDNumber::Flat);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lcdPoints);


        horizontalLayout->addLayout(formLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        lblStatus = new QLabel(centralwidget);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));

        verticalLayout_3->addWidget(lblStatus);

        txtCode = new QTextEdit(centralwidget);
        txtCode->setObjectName(QString::fromUtf8("txtCode"));
        QPalette palette1;
        QBrush brush2(QColor(51, 188, 24, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        txtCode->setPalette(palette1);
        QFont font4;
        font4.setFamily(QString::fromUtf8("FreeMono"));
        txtCode->setFont(font4);
        txtCode->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        txtCode->setAcceptRichText(false);

        verticalLayout_3->addWidget(txtCode);

        btnProcess = new QPushButton(centralwidget);
        btnProcess->setObjectName(QString::fromUtf8("btnProcess"));
        QFont font5;
        font5.setPointSize(12);
        btnProcess->setFont(font5);
        btnProcess->setFlat(false);

        verticalLayout_3->addWidget(btnProcess);

        btnNext = new QPushButton(centralwidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));

        verticalLayout_3->addWidget(btnNext);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        lcdLevel = new QLCDNumber(centralwidget);
        lcdLevel->setObjectName(QString::fromUtf8("lcdLevel"));
        lcdLevel->setFrameShape(QFrame::WinPanel);
        lcdLevel->setSegmentStyle(QLCDNumber::Flat);

        verticalLayout_4->addWidget(lcdLevel);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        txtChallenge = new QTextEdit(centralwidget);
        txtChallenge->setObjectName(QString::fromUtf8("txtChallenge"));
        QPalette palette2;
        QBrush brush3(QColor(24, 217, 214, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        txtChallenge->setPalette(palette2);
        QFont font6;
        font6.setFamily(QString::fromUtf8("FreeMono"));
        font6.setPointSize(12);
        font6.setBold(false);
        font6.setWeight(50);
        txtChallenge->setFont(font6);
        txtChallenge->setFrameShape(QFrame::Panel);
        txtChallenge->setFrameShadow(QFrame::Raised);
        txtChallenge->setReadOnly(true);

        verticalLayout_5->addWidget(txtChallenge);


        verticalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_2->addLayout(verticalLayout_6);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 848, 21));
        menuHace = new QMenu(menubar);
        menuHace->setObjectName(QString::fromUtf8("menuHace"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHace->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Hace!", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionLanguage->setText(QApplication::translate("MainWindow", "Language", 0, QApplication::UnicodeUTF8));
        actionHow_to_Hace->setText(QApplication::translate("MainWindow", "How to Hace", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        btnNew->setText(QApplication::translate("MainWindow", "&New", 0, QApplication::UnicodeUTF8));
        btnStart->setText(QApplication::translate("MainWindow", "&Start", 0, QApplication::UnicodeUTF8));
        btnPause->setText(QApplication::translate("MainWindow", "&Pause", 0, QApplication::UnicodeUTF8));
        btnStop->setText(QApplication::translate("MainWindow", "&End", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Hace Output...", 0, QApplication::UnicodeUTF8));
        txtOutput->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Nimbus Mono L'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#ffff33;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        GameTime->setDisplayFormat(QApplication::translate("MainWindow", " hh:mm::ss", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Your Rep Power!", 0, QApplication::UnicodeUTF8));
        lblStatus->setText(QApplication::translate("MainWindow", "get yo hack on ...", 0, QApplication::UnicodeUTF8));
        txtCode->setDocumentTitle(QString());
        txtCode->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'FreeMono'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">//w31c0m3 : y0u7 c0d3 h3r3...</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        btnProcess->setText(QApplication::translate("MainWindow", "pr&ocess_my_sh*t!", 0, QApplication::UnicodeUTF8));
        btnNext->setText(QApplication::translate("MainWindow", "Ne&xt Hack >>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Hace Level", 0, QApplication::UnicodeUTF8));
        txtChallenge->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'FreeMono'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">welcome to hace</p></body></html>", 0, QApplication::UnicodeUTF8));
        menuHace->setTitle(QApplication::translate("MainWindow", "Hace!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
