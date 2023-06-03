#ifndef PROGRESS_H
#define PROGRESS_H

#include <QDialog>
#include <QDir>
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
namespace Ui {
class progress;
}

class progress : public QDialog
{
    Q_OBJECT

public:
    explicit progress(QWidget *parent = 0);
    ~progress();

private:
    Ui::progress *ui;
    void extractProgressFromFile(QStringList& dates, QVector<int>& times);
};

#endif // PROGRESS_H
