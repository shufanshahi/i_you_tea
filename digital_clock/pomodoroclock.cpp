#include "pomodoroclock.h"
#include "ui_pomodoroclock.h"

#include <QUrl>
int flag=1,flag2=1;

PomodoroClock::PomodoroClock(QWidget *parent)
    : QMainWindow(parent)
{

    // Initialize the UI
    //m_timerLabel = new QLabel("25:00", this);
    m_pomodorotime= new QLabel("Pomodoro Time",this);
    m_breaktime = new QLabel("Break Time",this);
    m_sessions = new QLabel("Sessions",this);
    m_lcdNumber = new QLCDNumber(this);
    m_lcdNumber->setDigitCount(5);
    m_startButton = new QPushButton("Start", this);
   // pback = new QPushButton("back",this);
    m_stopButton = new QPushButton("Stop", this);
    m_resetButton = new QPushButton("Reset", this);
    //TaskDone = new QPushButton("Task Done",this);
    m_spinBox = new QSpinBox(this);
    resting = new QSpinBox(this);
    sessions = new QSpinBox(this);
    m_spinBox->setRange(1, 1000);
    m_spinBox->setValue(25);
    resting->setValue(5);
    sessions->setValue(1);


    // Connect the start, stop, and reset buttons to their respective slots
    connect(m_startButton, &QPushButton::clicked, this, &PomodoroClock::startTimer);
    connect(m_stopButton, &QPushButton::clicked, this, &PomodoroClock::stopTimer);
    connect(m_resetButton, &QPushButton::clicked, this, &PomodoroClock::resetTimer);

    // Create the timer and set the initial time
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    m_timerRunning = false;
    m_minutesLeft = m_spinBox->value();
    m_sessionsleft= sessions->value();
    m_secondleft = 00;

    // Connect the timer to its update slot
    connect(m_timer, &QTimer::timeout, this, &PomodoroClock::updateTimer);


    // Set up the layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    //m_startButton->resize(20,30);
    //m_startButton->resize(2,3);

    layout->addWidget(m_lcdNumber);
    layout->addWidget(m_startButton);
    layout->addWidget(m_stopButton);
    layout->addWidget(m_resetButton);
    layout->addWidget(m_pomodorotime);
    layout->addWidget(m_spinBox);
    layout->addWidget(m_breaktime);
    layout->addWidget(resting);
    layout->addWidget(m_sessions);
    layout->addWidget(sessions);
    //m_startButton->setGeometry(25,50,60,60);
    //m_breaktime->setGeometry(0,0,20,20);
   // m_startButton->resize(20,30);
    //layout->addWidget(pback);
   // m_startButton->resize(20,30);
    //layout->addWidget(TaskDone);
    //m_startButton->setFixedSize(20,20);
    //m_breaktime->setFixedWidth(200);
    //m_spinBox->setFixedHeight(400);
    //m_lcdNumber->setFixedHeight(200);

    setCentralWidget(centralWidget);

    //m_minutesLeft = m_spinBox->value();
}

void PomodoroClock::startTimer()
{
    if (!m_timerRunning) {
        if(flag)
        {
             m_minutesLeft = m_spinBox->value();
             m_sessionsleft= sessions->value();
             m_sessionsleft--;

            flag=0;
        }
        m_timerRunning = true;
        //m_minutesLeft = m_spinBox->value();
        m_timer->start();
    }
}

void PomodoroClock::stopTimer()
{
    if (m_timerRunning)
    {
        m_timerRunning = false;
        //m_minutesLeft = m_spinBox->value();
        m_timer->stop();
    }
}

void PomodoroClock::resetTimer()
{
    stopTimer();
    //m_minutesLeft = 25;
    m_minutesLeft = m_spinBox->value();
    m_sessionsleft= sessions->value();
    m_secondleft = 0;
    //m_lcdNumber->display("25:00");
    updateTimer();
}

void PomodoroClock::updateTimer()
{
    //m_minutesLeft = m_spinBox->value()-1;
    if (m_minutesLeft == 0 && m_secondleft==0)
    {

        stopTimer();

         m_lcdNumber->display("00:00");

         if(m_sessionsleft==0)
         return;
         else if(flag2)
         {

             m_minutesLeft=resting->value();

             flag2=0;
         }
         else
         {
             flag2=1;
             m_sessionsleft--;
             m_minutesLeft = m_spinBox->value();
         }
    }
    else if(m_secondleft == 0 && m_minutesLeft!=0)
    {
        m_minutesLeft--;
        m_secondleft=59;
    }
    else
    {
        m_secondleft--;


    }

    int minutes = m_minutesLeft;
    int seconds = m_secondleft;

    // Update the label with the new time
    QString timeString = QString("%1:%2").arg(minutes, 2, 10, QLatin1Char('0'))
                                          .arg(seconds, 2, 10, QLatin1Char('0'));
   m_lcdNumber->display(timeString);
}
