#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.resize(628,1122);
    //w.resize(300,400);

    w.show();

    return a.exec();
}
