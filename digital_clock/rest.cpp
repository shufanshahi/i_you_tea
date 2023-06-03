#include "rest.h"
#include "ui_rest.h"

rest::rest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rest)
{
    ui->setupUi(this);
}

rest::~rest()
{
    delete ui;
}
