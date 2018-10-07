#include "registration.h"
#include "ui_registration.h"
#include <QMessageBox>

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

    bool isOpen = ui->password->text() == ui->repeatPassword->text();

    if (isOpen){
        int res = successMsg.exec();
        if (res == QMessageBox::Ok){
            this->close();
        }
    } else {
        int res = failMsg.exec();
    }
}
