#include "education.h"
#include "ui_education.h"
#include "add_card/add_card.h"
#include "add_category/add_category.h"

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
    add_card_window.user_id = this->user_id;
    add_card_window.setModal(true);
    add_card_window.exec();
}

void Education::on_add_category_button_clicked()
{
    AddCategory add_category_window;
    add_category_window.user_id = this->user_id;
    add_category_window.setModal(true);
    add_category_window.exec();
}
