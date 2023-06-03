#ifndef REST_H
#define REST_H

#include <QDialog>

namespace Ui {
class rest;
}

class rest : public QDialog
{
    Q_OBJECT

public:
    explicit rest(QWidget *parent = 0);
    ~rest();

private:
    Ui::rest *ui;
};

#endif // REST_H
