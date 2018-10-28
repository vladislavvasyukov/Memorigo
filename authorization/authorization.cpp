#include "authorization.h"
#include "ui_authorization.h"
#include "education/education.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

Authorization::Authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);
}

Authorization::~Authorization()
{
    delete ui;
}

void Authorization::on_cancelButton_clicked()
{
    this->close();
}

void Authorization::on_authorizationButton_clicked()
{
    QMessageBox successMsg;
    successMsg.setIcon(QMessageBox::Information);

    QMessageBox failMsg;
    failMsg.setText("Ошибка!");
    failMsg.setInformativeText("Неверный логин или пароль! Попробуйте ещё раз.");
    failMsg.setIcon(QMessageBox::Information);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:\\my_projects\\database_memorigo.db");
    bool isOpen = db.open();

    QSqlQuery query;
    query.prepare("SELECT name, login, password FROM users WHERE login=:login AND password=:password");
    query.bindValue(":login", ui->login->text());
    query.bindValue(":password", ui->password->text());
    query.exec();

    QString name = "";
//    QString login = query.value(1).toString();
//    QString password = query.value(2).toString();
    while(query.next()) {
        name = query.value(0).toString();
    }

    if (isOpen && name.length() > 0) {
        successMsg.setText("Приветствую Вас, " + name + "!");
        int res = successMsg.exec();
        if (res == QMessageBox::Ok){
            this->close();
            Education window;
            window.setModal(true);
            window.exec();
        }
    } else {
        int res = failMsg.exec();
    }
}
