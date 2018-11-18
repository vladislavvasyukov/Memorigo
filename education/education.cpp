#include "QStandardItemModel"
#include "QMessageBox"
#include "education.h"
#include "QDebug"
#include "QSqlQuery"
#include "ui_education.h"
#include "add_card/add_card.h"
#include "add_category/add_category.h"

Education::Education(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Education)
{
    ui->setupUi(this);
    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *item;

    QSqlQuery query;
    query.prepare("SELECT title FROM decks WHERE user_id=2");
//    query.bindValue(":user_id", this->user_id);
    query.exec();

    QString title = "";

    int decks_count = 0;
    while(query.next()) {
        title = query.value(0).toString();
        item = new QStandardItem(title);
        model->appendRow(item);
        decks_count++;
    }

    ui->decksList->setModel(model);
    ui->decksList->resize(250, decks_count * 18);
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

void Education::on_decksList_clicked(const QModelIndex &index)
{
    QString deck = index.data(Qt::DisplayRole).toString();

    QMessageBox failMsg;
    failMsg.setText(QString("Ошибка"));
    failMsg.setInformativeText("Неверный логин или пароль! Попробуйте ещё раз.");
    failMsg.setIcon(QMessageBox::Information);
    failMsg.exec();
}
