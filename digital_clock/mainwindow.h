#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>

#include<QDateTime>
#include<QString>
#include<QTimer>
#include"pomodoroclock.h"
#include<QDebug>
#include"listwidget.h"
#include "list.h"
#include "ui_list.h"
#include "subjects.h"
#include "ui_subjects.h"
#include "pommo.h"
#include "ui_pommo.h"





namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void Date_Time_Display_slot();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* DateTime;
    PomodoroClock* hello;
    pommo* pomo;
    progress* progressBar;
    //ListWidget* task;
    list *task;
    subjects *sub;





};


#endif // MAINWINDOW_H
