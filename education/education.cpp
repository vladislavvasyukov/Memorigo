#include "education.h"
#include "ui_education.h"

Education::Education(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Education)
{
    ui->setupUi(this);
}

Education::~Education()
{
    delete ui;
}
