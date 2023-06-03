#include "notepad.h"
#include "ui_notepad.h"
#include <QDebug>
#include<string.h>
#include <QString>
#include <fstream>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
QString textt1,time1;

notepad::notepad(const QString &textt,const QString  &timee,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notepad)
{
    ui->setupUi(this);
    textt1=textt;
    time1=timee;
    loadItemsFromFile(textt,timee);
}

notepad::~notepad()
{
    delete ui;
}

void notepad::on_pushButton_clicked()
{
    saveItemsToFile();
}
void notepad::loadItemsFromFile(QString textt, QString timee)
{

    QFile file(textt+timee+".txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        //QString line1 = stream.readLine();
        QTextStream in(&file);
        QString line2 = in.readAll();
        ui->textEdit->setText(line2);
        /*while (!stream.atEnd())
        {
            QString line = stream.readLine();
            //QString item = QString::fromStdString(line);
            //ui->listWidget->addItem(line);
            ui->textEdit->setText(line);

        }*/
    }
        file.close();
 }
void notepad::saveItemsToFile() {
     QFile file(textt1+time1+".txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QTextStream out(&file);
        QString line2 = ui->textEdit->toPlainText();
        out<<line2;
        /*while (!stream.atEnd())
        {
            QString line = stream.readLine();
            //QString item = QString::fromStdString(line);
            //ui->listWidget->addItem(line);
            //ui->textEdit->setText(line);
            stream<< line << endl;

        }*/
                /*for (int i = 0; i < ui->listWidget->count(); ++i) {
                    QString item = ui->listWidget->item(i)->text();
                   stream<< item << endl;*/
                }
        file.close();
    }

