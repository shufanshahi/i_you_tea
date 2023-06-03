#include "pomo.h"
#include "ui_pomo.h"

pomo::pomo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pomo)
{
    ui->setupUi(this);
}

pomo::~pomo()
{
    delete ui;
}
