#include "add_card.h"
#include "ui_add_card.h"
#include <QMessageBox>
#include <QSqlQuery>

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
    QMessageBox failMsg;
    failMsg.setText("Ошибка!");
    failMsg.setInformativeText("Произошла ошибка!");
    failMsg.setIcon(QMessageBox::Information);

    // убрать
    bool isOpen = 1;

    QSqlQuery query;
//    query.prepare("INSERT INTO decks (title, user_id)"
//             "VALUES (:title, :user_id)");
//    query.bindValue(":title", ui->deck_title->text());
//    query.bindValue(":user_id", this->user_id);
//    query.exec();

    // Здесь должна быть проверка, что запрос к базе выполнился успешно.
    if (isOpen){
        this->close();
    } else {
        int res = failMsg.exec();
    }
}
