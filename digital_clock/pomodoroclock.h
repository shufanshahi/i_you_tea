#ifndef POMODOROCLOCK_H
#define POMODOROCLOCK_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QLCDNumber>
#include <QDialog>
#include <QSpinBox>


class PomodoroClock : public QMainWindow
{
    Q_OBJECT

public:
    PomodoroClock(QWidget *parent = nullptr);

private slots:
    void startTimer();
    void stopTimer();
    void resetTimer();
    void updateTimer();

private:
    QLCDNumber *m_lcdNumber;
    QLabel *m_timerLabel;
    QLabel *m_pomodorotime;
    QLabel *m_breaktime;
    QLabel *m_sessions;
    QPushButton *m_startButton;
    //QPushButton *pback;
    QPushButton *m_stopButton;
    QPushButton *m_resetButton;
    QTimer *m_timer;
    int m_minutesLeft;
    int m_secondleft;
    int m_sessionsleft;

    bool m_timerRunning;
    QSpinBox *m_spinBox;
    QSpinBox *resting;
    QSpinBox *sessions;
   // QPushButton* TaskDone;

};

#endif // POMODOROCLOCK_H
