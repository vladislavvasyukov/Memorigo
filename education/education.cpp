#include "education.h"
#include "ui_education.h"
#include "add_card/add_card.h"

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

void Education::on_add_card_button_clicked()
{
    AddCard add_card_window;
    add_card_window.setModal(true);
    add_card_window.exec();
}
