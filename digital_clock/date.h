#ifndef DATE_H
#define DATE_H
#include "notepad.h"
#include "ui_notepad.h"

#include <QDialog>

namespace Ui {
class date;
}

class date : public QDialog
{
    Q_OBJECT

public:
    explicit date(const QString &text,QWidget *parent = 0);
    ~date();

private slots:
    void on_pushButton_clicked();
    void loadItemsFromFile(QString text);
    void saveItemsToFile();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::date *ui;
    notepad *note;

};

#endif // DATE_H
