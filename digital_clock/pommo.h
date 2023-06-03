#ifndef POMMO_H
#define POMMO_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QLCDNumber>
#include <QDialog>
#include <QSpinBox>
#include <fstream>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include "progress.h"
#include "ui_progress.h"
#include <QDateTime>
#include <QFile>
#include <QStringList>
#include <algorithm>



namespace Ui {
class pommo;
}

class pommo : public QMainWindow
{
    Q_OBJECT

public:
    explicit pommo(QWidget *parent = 0);
    ~pommo();

private slots:
    void on_startButton_clicked();
    void updateTimer();


    void on_stopButton_clicked();

    void on_resetButton_clicked();

//    void on_progressPushButton_clicked();

    void saveProgressToFile();
//    void removeOldProgressEntries(const QString& filePath);

private:
    Ui::pommo *ui;
    QTimer* timer;
//    Progress *progressBar;
    bool timerRunning;
    int remainingMinutes;
    int remainingSeconds;
    int remainingSessions;
};

#endif // POMMO_H
