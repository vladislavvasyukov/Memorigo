#include "add_card.h"
#include "ui_add_card.h"

AddCard::AddCard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCard)
{
    ui->setupUi(this);
}

AddCard::~AddCard()
{
    delete ui;
}

void AddCard::on_cancel_button_clicked()
{
    this->close();
}

void AddCard::on_add_card_button_clicked()
{

}
