#include "progress.h"
#include "ui_progress.h"

progress::progress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::progress)
{
    ui->setupUi(this);
    QStringList dates;
    QVector<int> times;
    QBarSet *set = new QBarSet("Progress");
    extractProgressFromFile(dates,times);
    *set << times[0] << times[1]<< times[2]<< times[3]<< times[4]<< times[5]<< times[6];
    QBarSeries *series = new QBarSeries();
    series->append(set);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Progress Bar");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;
    categories << dates[0]<< dates[1]<< dates[2]<< dates[3]<< dates[4]<< dates[5]<< dates[6];
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(chartView);

    ui->horizontalFrame->addLayout(layout);
}

progress::~progress()
{
    delete ui;
}

void progress::extractProgressFromFile(QStringList& dates, QVector<int>& times) {
    QString filePath = QDir::currentPath() + QDir::separator() + "progress.txt";
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList parts = line.split(' ');
            if (parts.size() == 2) {
                dates.append(parts[0]);
                times.append(parts[1].toInt());
            }
        }

        file.close();
    }
}
