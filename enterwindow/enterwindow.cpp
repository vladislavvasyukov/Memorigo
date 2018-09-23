#include "enterwindow.h"
#include "ui_enterwindow.h"
#include "authorization\authorization.h"
#include "registration\registration.h"

EnterWindow::EnterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EnterWindow)
{
    ui->setupUi(this);
}

EnterWindow::~EnterWindow()
{
    delete ui;
}

void EnterWindow::on_registrationButon_clicked()
{
    hide();
    Registration registration;
    registration.setModal(true);
    registration.exec();
}

void EnterWindow::on_authorizationButton_clicked()
{
    hide();
    Authorization authorization;
    authorization.setModal(true);
    authorization.exec();
}
