#ifndef LIST_H
#define LIST_H
#include <QWidget>
#include <QListWidget>
#include <QPushButton>

#include <QMainWindow>
#include<QDialog>
//#include "mainwindow.h"
//#include "ui_mainwindow.h"

namespace Ui {
class list;
}

class list : public QDialog
{
    Q_OBJECT

public:
    explicit list(QWidget *parent = 0);
    ~list();

private slots:
    //void on_calendarWidget_activated(const QDate &date);

    void on_calendarWidget_selectionChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void loadItemsFromFile(QString date1);

    void saveItemsToFile(QString date1);

    void on_pushButton_3_clicked();

    //void on_pushButton_5_clicked();

private:
    Ui::list *ui;
    //MainWindow *maiin;
    class CheckableListItem : public QListWidgetItem
    {
    public:
        CheckableListItem(const QString& text) : QListWidgetItem(text)
        {
            setFlags(flags() | Qt::ItemIsUserCheckable);
            setCheckState(Qt::Unchecked);
        }
        QVariant data(int role) const override;
        //QListWidget *listWidget;
    };
};

#endif // LIST_H
