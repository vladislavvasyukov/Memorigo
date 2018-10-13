#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);
}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_cancelButton_clicked()
{
    this->close();
}

void Registration::on_registrationButton_clicked()
{
    QMessageBox successMsg;
    successMsg.setText("Information");
    successMsg.setInformativeText("Поздравляем! Вы успешно зарегистрировались!");
    successMsg.setIcon(QMessageBox::Information);

    QMessageBox failMsg;
    failMsg.setText("Error");
    failMsg.setInformativeText("Неправильное подтверждение пароля! Попробуйте ещё раз.");
    failMsg.setIcon(QMessageBox::Information);

    bool isTruePassword = ui->password->text() == ui->repeatPassword->text();

    if (isTruePassword){
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:\\my_projects\\database_memorigo.db");
        bool isOpen = db.open();

        QSqlQuery query;
        query.prepare("INSERT INTO users (name, login, password) VALUES (:name, :login, :password)");
        query.bindValue(":name", ui->name->text());
        query.bindValue(":login", ui->login->text());
        query.bindValue(":password", ui->login->text());
        query.exec();
        if (isOpen) {
            int res = successMsg.exec();
            if (res == QMessageBox::Ok){
                this->close();
            }
        }
    } else {
        int res = failMsg.exec();
    }
}
