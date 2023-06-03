#include "date.h"
#include "ui_date.h"
#include <QDebug>
#include <string.h>
#include <QString>
#include <fstream>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>



QString textt;
date::date(const QString &text ,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::date)
{
    ui->setupUi(this);
    //ui->listWidget->addItem(text);

    loadItemsFromFile(text);
    textt = text;
}

date::~date()
{
    delete ui;
}

void date::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text().trimmed();

    if (!text.isEmpty())
    {
        ui->listWidget->addItem(text);
        ui->lineEdit->clear();
    }
}
void date::on_pushButton_2_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    if (item)
    {
        QString timee = item->text();
        note = new notepad(textt,timee);
        hide();
        note->show();

    }
}
void date::on_pushButton_3_clicked()
{
    saveItemsToFile();
}
void date::on_pushButton_4_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    if (item)
    {
        delete item;
        ui->listWidget->setCurrentRow(-1);
        //saveItemsToFile();
    }
}

void date::loadItemsFromFile(QString text) {
   /* std::ifstream file(text+"date.txt");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            QString item = QString::fromStdString(line);
            ui->listWidget->addItem(item);

        }*/
    //QString DateAndTime = QDateTime :: currentDateTime().toString("HH:mm:ss");
    QFile file(text+"date.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        while (!stream.atEnd())
        {
            QString line = stream.readLine();
            //QString item = QString::fromStdString(line);
            ui->listWidget->addItem(line);
        }
    }
        file.close();
    }



void date::saveItemsToFile() {
    /*std::ofstream file(text+"date.txt");
    if (file.is_open()) {
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            QString item = ui->listWidget->item(i)->text();
            file << item.toStdString() << std::endl;
        }*/
    //QFile file(date1+".txt");
    QFile file(textt+"date.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

                for (int i = 0; i < ui->listWidget->count(); ++i) {
                    QString item = ui->listWidget->item(i)->text();
                         stream<< item << "\n";
                }
                file.close();
    }
}



