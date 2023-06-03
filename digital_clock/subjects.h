#ifndef SUBJECTS_H
#define SUBJECTS_H


#include <QMainWindow>
#include <QDialog>
#include "date.h"

namespace Ui {
class subjects;
}

class subjects : public QDialog
{
    Q_OBJECT

public:
    explicit subjects(QWidget *parent = 0);
    ~subjects();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void loadItemsFromFile();
    void saveItemsToFile();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::subjects *ui;
    date *datee;
};

#endif // SUBJECTS_H
