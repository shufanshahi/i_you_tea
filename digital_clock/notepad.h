#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QDialog>


namespace Ui {
class notepad;
}

class notepad : public QDialog
{
    Q_OBJECT

public:
    explicit notepad(const QString &textt,const QString  &timee,QWidget *parent = 0);
    ~notepad();

private slots:
    void on_pushButton_clicked();
    void loadItemsFromFile(QString textt, QString timee);
    void saveItemsToFile();

private:
    Ui::notepad *ui;

};

#endif // NOTEPAD_H
