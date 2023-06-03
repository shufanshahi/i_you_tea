#include "listwidget.h"
#include "ui_listwidget.h"
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QCoreApplication>
#include <fstream>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <bits/stdc++.h>
#include <string.h>



ListWidget::ListWidget(QWidget* parent) : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    // Create the list widget
    listWidget = new QListWidget(this);
    layout->addWidget(listWidget);

    // Create the line edit for adding new items
    addItemLineEdit = new QLineEdit(this);
    layout->addWidget(addItemLineEdit);

    // Create the add item button
    addItemButton = new QPushButton("Add Item", this);
    layout->addWidget(addItemButton);

    // Create the delete item button
    deleteItemButton = new QPushButton("Delete Selected Item", this);
    layout->addWidget(deleteItemButton);

    //create the start pomodoro button;
    startPomodoro = new QPushButton("Start Pomodoro",this);
    layout->addWidget(startPomodoro);

    //connect start pomodoro button with the list
    connect(startPomodoro,&QPushButton::clicked,this,[this]()
    {
        hello = new PomodoroClock();
        hello->resize(1122,628);
        hello->show();
        //hello->sho

        QListWidgetItem* item = listWidget->currentItem();
        if (item)
        {
            delete item;
            listWidget->setCurrentRow(-1);
            saveItemsToFile();
        }
        else

        {
            //QListWidgetItem* item = listWidget->currentItem();
            delete listWidget->item(0);
            listWidget->setCurrentRow(-1);
            saveItemsToFile();

        }
    });

    // Connect the add item button to the slot for adding items
    connect(addItemButton, &QPushButton::clicked, this, [this]() {
        QString text = addItemLineEdit->text().trimmed();
        if (!text.isEmpty())
        {
            listWidget->addItem(text);
            addItemLineEdit->clear();
            saveItemsToFile();

        }
    });

    // Connect the delete item button to the slot for deleting items
    connect(deleteItemButton, &QPushButton::clicked, this, [this]() {
        QListWidgetItem* item = listWidget->currentItem();
        if (item)
        {
            delete item;
            listWidget->setCurrentRow(-1);
            saveItemsToFile();
        }
    });

    // Load the list items from the file
    loadItemsFromFile();
    //saveItemsToFile();

    // Connect the slot for saving the list items when the application is about to quit
    connect(qApp, &QCoreApplication::aboutToQuit, this, &ListWidget::saveItemsToFile);
    //connect(qApp, &QWidget::aboutToQuit, this, &ListWidget::saveItemsToFile);
}

// Load the list items from the file
void ListWidget::loadItemsFromFile() {
    std::ifstream file("list.txt");
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            QString item = QString::fromStdString(line);
            listWidget->addItem(item);
        }
        file.close();
    }
}
// Save the list items to the file
void ListWidget::saveItemsToFile() {
    std::ofstream file("list.txt");
    if (file.is_open()) {
        for (int i = 0; i < listWidget->count(); ++i) {
            QString item = listWidget->item(i)->text();
            file << item.toStdString() << std::endl;
        }
        file.close();
    }
}
