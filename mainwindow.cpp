#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->actionStart_new_game, SIGNAL(triggered()), ui->Glass, SLOT(slotNewGame()));
QObject::connect(ui->Glass, SIGNAL(signalNextNewFigure(figure*)),  ui->WidgetWidget, SLOT(slotNextNewFigure(figure*)));
QObject::connect(ui->Glass, SIGNAL(signalSetLCD(int)),  ui->lcdNumber, SLOT(display(int)));
QObject::connect(ui->actionAbout, &QAction::triggered, this, [this](){QMessageBox::about(this,"About game","Game is created by Dolotova");});

}

MainWindow::~MainWindow()
{
    delete ui;
}


