/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glass.h"
#include "nextfigure.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart_new_game;
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *NextElement;
    NextFigure *WidgetWidget;
    QSpacerItem *verticalSpacer;
    glass *Glass;
    QVBoxLayout *verticalLayout_2;
    QPushButton *StartButton;
    QPushButton *ExitButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *Score;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menuBar;
    QMenu *menuGame;
    QMenu *menuInformation;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(594, 562);
        actionStart_new_game = new QAction(MainWindow);
        actionStart_new_game->setObjectName(QStringLiteral("actionStart_new_game"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        NextElement = new QLabel(centralWidget);
        NextElement->setObjectName(QStringLiteral("NextElement"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        NextElement->setFont(font);

        verticalLayout->addWidget(NextElement);

        WidgetWidget = new NextFigure(centralWidget);
        WidgetWidget->setObjectName(QStringLiteral("WidgetWidget"));
        WidgetWidget->setMinimumSize(QSize(160, 150));

        verticalLayout->addWidget(WidgetWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        Glass = new glass(centralWidget);
        Glass->setObjectName(QStringLiteral("Glass"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Glass->setPalette(palette);
        Glass->setFocusPolicy(Qt::StrongFocus);
        Glass->setAutoFillBackground(true);
        Glass->setProperty("rows", QVariant(20u));
        Glass->setProperty("columns", QVariant(10u));

        horizontalLayout_2->addWidget(Glass);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        StartButton = new QPushButton(centralWidget);
        StartButton->setObjectName(QStringLiteral("StartButton"));

        verticalLayout_2->addWidget(StartButton);

        ExitButton = new QPushButton(centralWidget);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));

        verticalLayout_2->addWidget(ExitButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        Score = new QLabel(centralWidget);
        Score->setObjectName(QStringLiteral("Score"));
        Score->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(Score);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        verticalLayout_2->addWidget(lcdNumber);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 594, 26));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        menuInformation = new QMenu(menuBar);
        menuInformation->setObjectName(QStringLiteral("menuInformation"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGame->menuAction());
        menuBar->addAction(menuInformation->menuAction());
        menuGame->addAction(actionStart_new_game);
        menuGame->addAction(actionExit);
        menuInformation->addAction(actionAbout);
        mainToolBar->addAction(actionStart_new_game);
        mainToolBar->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(StartButton, SIGNAL(clicked()), actionStart_new_game, SLOT(trigger()));
        QObject::connect(ExitButton, SIGNAL(clicked()), actionExit, SLOT(trigger()));
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionStart_new_game->setText(QApplication::translate("MainWindow", "Start new game", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        NextElement->setText(QApplication::translate("MainWindow", "Next Figure", nullptr));
        StartButton->setText(QApplication::translate("MainWindow", "New Game", nullptr));
        ExitButton->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        Score->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", nullptr));
        menuInformation->setTitle(QApplication::translate("MainWindow", "Information", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
