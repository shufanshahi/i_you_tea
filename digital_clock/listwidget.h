#pragma once
#include <QWidget>
#include<QDialog>
#include "pomodoroclock.h"

class QListWidget;
class QLineEdit;
class QPushButton;

class ListWidget : public QWidget {
public:
    ListWidget(QWidget* parent = nullptr);


private:
    QListWidget* listWidget;
    QLineEdit* addItemLineEdit;
    QPushButton* addItemButton;
    QPushButton* deleteItemButton;
    QPushButton* startPomodoro;
    PomodoroClock* hello;


    void loadItemsFromFile();
    void saveItemsToFile();
};
