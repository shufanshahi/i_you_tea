#include "subjects.h"
#include "ui_subjects.h"
#include <QListWidget>
#include <fstream>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <bits/stdc++.h>
#include <string.h>

subjects::subjects(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::subjects)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&on_pushButton_clicked);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&on_pushButton_3_clicked);
    loadItemsFromFile();
}

subjects::~subjects()
{
    delete ui;
}

void subjects::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text().trimmed();

    if (!text.isEmpty())
    {
        ui->listWidget->addItem(text);
        ui->lineEdit->clear();
    }

}
void subjects::on_pushButton_2_clicked()
{
    saveItemsToFile();
}




void subjects::on_pushButton_3_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    if (item)
    {
            hide();
        QString text = item->text();
        datee = new date(text);
        datee->show();


    }
}
void subjects::on_pushButton_4_clicked()
{

    QListWidgetItem* item = ui->listWidget->currentItem();
    if (item)
    {
        delete item;
        ui->listWidget->setCurrentRow(-1);
        //saveItemsToFile();
    }
}
void subjects::loadItemsFromFile() {
    std::ifstream file("subjects.txt");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            QString item = QString::fromStdString(line);
            ui->listWidget->addItem(item);
        }
        file.close();
    }
}
void subjects::saveItemsToFile() {
    std::ofstream file("subjects.txt");
    if (file.is_open()) {
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            QString item = ui->listWidget->item(i)->text();
            file << item.toStdString() << std::endl;
        }
        file.close();
    }
}



