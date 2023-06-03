#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pomodoroclock.h"
#include "progress.h"
#include "ui_progress.h"
#include<QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DateTime = new QTimer();
    connect(DateTime,SIGNAL(timeout()),this,SLOT(Date_Time_Display_slot()));
    DateTime->setInterval(1000);
    DateTime->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Date_Time_Display_slot()
{

    QDateTime dwtee = QDateTime::currentDateTime();
    QString Time = QDateTime :: currentDateTime().toString("HH:mm:ss");
    ui->lcdNumber->display(Time);

    QString Dateee = dwtee.toString("yyyy-MM-dd");
    ui->labelCalendar->setText(Dateee);
    ui->labelCalendar->show();

}


void MainWindow::on_pushButton_clicked()
{

    /*hello = new PomodoroClock();
    hello->resize(1122,628);
    hello->show();*/
    pomo =new pommo();
    pomo->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    task = new list();
    //task->resize(1122,628);
    task->show();

   //return app.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    sub = new subjects();
    sub->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    progressBar = new progress();
    progressBar->show();

}

