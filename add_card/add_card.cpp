#include "add_card.h"
#include "ui_add_card.h"
#include "base_combo_model.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

AddCard::AddCard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCard)
{
    ui->setupUi(this);
    ui->category->setModel( new BaseComboModel( "title", "decks WHERE user_id=2", this ) );
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
//    Здесь нужна проверка. Если category_id = 0, то либо вывести предупреждение, либо создать колоду "Новая колода"
    query.prepare("INSERT INTO cards (question, answer, deck_id)"
             "VALUES (:question, :answer, :deck_id)");
    query.bindValue(":question", ui->question->text());
    query.bindValue(":answer", ui->answer->text());
    query.bindValue(":deck_id", ui->category->itemData( ui->category->currentIndex(), Qt::UserRole ));
    query.exec();

    // Здесь должна быть проверка, что запрос к базе выполнился успешно.
    if (isOpen){
        this->close();
    } else {
        int res = failMsg.exec();
    }
}
