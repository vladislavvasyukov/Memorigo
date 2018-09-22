#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authorization.h"
#include "registration.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_registrationButon_clicked()
{
    hide();
    Registration registration;
    registration.setModal(true);
    registration.exec();
}

void MainWindow::on_authorizationButton_clicked()
{
    hide();
    Authorization authorization;
    authorization.setModal(true);
    authorization.exec();
}
