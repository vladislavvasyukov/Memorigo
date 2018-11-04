#include "add_category.h"
#include "ui_add_category.h"
#include "QDebug"
#include <QMessageBox>
#include <QSqlQuery>

AddCategory::AddCategory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCategory)
{
    ui->setupUi(this);
}

AddCategory::~AddCategory()
{
    delete ui;
}

void AddCategory::on_create_category_button_clicked()
{
    QMessageBox failMsg;
    failMsg.setText("Ошибка!");
    failMsg.setInformativeText("Произошла ошибка!");
    failMsg.setIcon(QMessageBox::Information);

    // убрать
    bool isOpen = 1;

    QSqlQuery query;
    query.prepare("INSERT INTO decks (title, user_id)"
             "VALUES (:title, :user_id)");
    query.bindValue(":title", ui->deck_title->text());
    query.bindValue(":user_id", this->user_id);
    query.exec();

    // Здесь должна быть проверка, что запрос к базе выполнился успешно.
    if (isOpen){
        this->close();
    } else {
        int res = failMsg.exec();
    }
}

void AddCategory::on_cancel_button_clicked()
{
    this->close();
}
