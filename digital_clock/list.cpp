#include "list.h"
#include "ui_list.h"
#include <QDebug>
#include <string.h>
#include <QString>
#include <fstream>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>




QVariant list::CheckableListItem::data(int role) const
{
    if (role == Qt::ForegroundRole && checkState() == Qt::Checked)
        return QColor(Qt::gray);

    return QListWidgetItem::data(role);
}

list::list(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::list)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&on_pushButton_clicked);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&on_pushButton_2_clicked);
    QString date1= ui->calendarWidget->selectedDate().toString();
    //qDebug()<<date1;

    loadItemsFromFile(date1);
    //saveItemsToFile();


}

list::~list()
{
    delete ui;
}


void list::on_calendarWidget_selectionChanged()
{
    QString date= ui->calendarWidget->selectedDate().toString();
    //qDebug()<<date<<std::endl;
    QString date2= ui->calendarWidget->selectedDate().toString();
    ui->listWidget->clear();

    loadItemsFromFile(date2);

}

void list::on_pushButton_clicked()
{
       //QString text = ui->lineEdit->text().trimmed();
       QLineEdit *lineEdit = findChild<QLineEdit *>();
       QString newItemText = lineEdit->text();
       if (!newItemText.isEmpty())
       {
           //ui->listWidget->addItem(text);
           CheckableListItem* newItem = new CheckableListItem(newItemText);
           ui->listWidget->addItem(newItem);
           ui->lineEdit->clear();
           //saveItemsToFile();

       }
}

void list::on_pushButton_2_clicked()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    if (item)
    {
        delete item;
        ui->listWidget->setCurrentRow(-1);
        //saveItemsToFile();
    }
}

void list::loadItemsFromFile(QString date1) {
    //QString zen= date1;
    QFile file(date1+".txt");
    //qDebug()<<"ygefyef";
//    std::ifstream file(date1);
   if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
       QTextStream stream(&file);

        /*std::string line;
        while (getline(file, line)) {
            QString item = QString::fromStdString(line);
            ui->listWidget->addItem(item);
        }*/
       while (!stream.atEnd())
       {
           QString line = stream.readLine();
           //QString item = QString::fromStdString(line);
           //ui->listWidget->addItem(line);
           if (line.startsWith("Checked: "))
           {
               QString itemText = line.mid(QString("Checked: ").length());
               CheckableListItem* item = new CheckableListItem(itemText);
               item->setCheckState(Qt::Checked);

               ui->listWidget->addItem(item);
               //item->setTextColor(Qt::red);
           }
           else if (line.startsWith("Unchecked: "))
           {
               QString itemText = line.mid(QString("Unchecked: ").length());
               CheckableListItem* item = new CheckableListItem(itemText);
               item->setCheckState(Qt::Unchecked);
               ui->listWidget->addItem(item);
           }

         }
        //file.flush();
        file.close();
    }
}

void list::on_pushButton_3_clicked()
{
    QString date1= ui->calendarWidget->selectedDate().toString();
    saveItemsToFile(date1);
}
void list::saveItemsToFile(QString date1)
{
    QFile file(date1+".txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

                /*for (int i = 0; i < ui->listWidget->count(); ++i) {
                    QString item = ui->listWidget->item(i)->text();
                   stream<< item << endl;
                }*/
        for (int i = 0; i < ui->listWidget->count(); ++i)
        {
            CheckableListItem* item = static_cast<CheckableListItem*>(ui->listWidget->item(i));
            if (item->checkState() == Qt::Checked)
               stream << "Checked: " << item->text() << "\n";
            else
               stream << "Unchecked: " << item->text() << "\n";
        }
                file.close();

     }
}

//void list::on_pushButton_5_clicked()
//{
//     //maiin = new MainWindow();
//     //maiin->show();
//     MainWindow *mainWindow = new MainWindow;  // Create an instance of the main window
//     mainWindow->show();
//}

