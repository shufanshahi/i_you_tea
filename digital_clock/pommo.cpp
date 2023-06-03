#include "pommo.h"
#include "ui_pommo.h"

bool firstTime = true , breakTime = true;
pommo::pommo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pommo)
{
    ui->setupUi(this);
    timer = new QTimer();
    timer->setInterval(1000);
    timerRunning = false;
    //remainingMinutes = ui->sessionTimeSpinBox->value();
    remainingSeconds = 0;
    //remainingSessions = ui->TotalSessionsSpinBox->value();

    connect(timer,&QTimer::timeout, this, &pommo::updateTimer );
    ui->TotalSessionsSpinBox->setValue(1);
    ui->sessionTimeSpinBox->setRange(1,1000);
    ui->sessionTimeSpinBox->setValue(25);
    //ui->TotalSessionsSpinBox->
    ui->breakTimeSpinBox->setValue(5);
    ui->lcdNumber->display("25:00");

}

pommo::~pommo()
{
    delete ui;
}



void pommo::on_startButton_clicked()
{
    if(!timerRunning){
        if(firstTime)
        {
            ui->label_4->setText("Time To Work");
            ui->label_4->show();
            saveProgressToFile();
            remainingMinutes = ui->sessionTimeSpinBox->value();
            remainingSessions = ui->TotalSessionsSpinBox->value()-1;

        }
        timerRunning = true;
        timer->start();
    }
}

void pommo::updateTimer() {
    if (remainingMinutes == 0 && remainingSeconds == 0) {
        on_stopButton_clicked();
        ui->lcdNumber->display("00:00");
        if (remainingSessions == 0) {
            return;
        } else if (breakTime) {
            for(int i=0;i<3;i++){
                Beep(1568, 200);
                Beep(1568, 200);
                Beep(1568, 200);
                //    Beep(1245, 1000);
                //    Beep(1397, 200);
                //    Beep(1397, 200);
                //    Beep(1397, 200);
                Beep(1175, 1000);
            }
            ui->label_4->setText("Its Break Time");
            ui->label_4->show();
            remainingMinutes = ui->breakTimeSpinBox->value();
            breakTime = false;
        } else {
            for(int i=0;i<3;i++){
                Beep(1568, 200);
                Beep(1568, 200);
                Beep(1568, 200);
                //    Beep(1245, 1000);
                //    Beep(1397, 200);
                //    Beep(1397, 200);
                //    Beep(1397, 200);
                Beep(1175, 1000);
            }
            ui->label_4->setText("Time To Work");
            ui->label_4->show();
            remainingSessions--;
            remainingMinutes = ui->sessionTimeSpinBox->value(); // Use session time spin box value here
            breakTime = true;
        }
    } else if (remainingSeconds == 0 && remainingMinutes != 0) {
        remainingMinutes--;
        remainingSeconds = 59;
    } else {
        remainingSeconds--;
    }

    int minutes = remainingMinutes;
    int seconds = remainingSeconds;
    QString timeString = QString("%1:%2").arg(minutes, 2, 10, QLatin1Char('0'))
                             .arg(seconds, 2, 10, QLatin1Char('0'));
    ui->lcdNumber->display(timeString);
}


void pommo::on_stopButton_clicked()
{
    if(timerRunning){
        timerRunning = false;
        timer->stop();
    }
}

void pommo::on_resetButton_clicked()
{
    ui->label_4->setText("Time To Work");
    ui->label_4->show();
    on_stopButton_clicked();
    remainingMinutes = ui->sessionTimeSpinBox->value();
    remainingSessions = ui->TotalSessionsSpinBox->value()-1;
    remainingSeconds = 0;
    saveProgressToFile();
    firstTime = false;
    updateTimer();
}




void pommo::saveProgressToFile() {
    QDateTime currentTime = QDateTime::currentDateTime();
    QString formattedDate = currentTime.toString("yyyy-MM-dd");
    QString filePath = QDir::currentPath() + QDir::separator() + "progress.txt";

    int totalRuntime = ui->sessionTimeSpinBox->value() * ui->TotalSessionsSpinBox->value();

    QFile file(filePath);
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream stream(&file);

        QStringList progressList;


        while (!stream.atEnd()) {
            QString line = stream.readLine();
            if (!line.isEmpty()) {
                progressList.append(line);
            }
        }


        bool dateFound = false;
        for (int i = 0; i < progressList.size(); ++i) {
            QString line = progressList.at(i);
            QStringList parts = line.split(' ');
            if (parts.size() == 2) {
                QString date = parts[0];
                if (date == formattedDate) {
                    int runtime = parts[1].toInt();
                    runtime += totalRuntime;
                    progressList.replace(i, date + " " + QString::number(runtime));
                    dateFound = true;
                    break;
                }
            }
        }


        if (!dateFound) {
            progressList.append(formattedDate + " " + QString::number(totalRuntime));
        }


        std::sort(progressList.begin(), progressList.end());

        if (progressList.size() > 7) {
            progressList.removeFirst();
        }

        // Clear the file contents
        file.resize(0);

        // Write the updated progress to the file
        for (const QString& entry : progressList) {
            stream << entry << '\n';
        }

        file.close();
    }

    firstTime = false;
}



