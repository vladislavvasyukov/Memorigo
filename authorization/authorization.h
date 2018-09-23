#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>

namespace Ui {
class Authorization;
}

class Authorization : public QDialog
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = 0);
    ~Authorization();

private slots:
    void on_cancelButton_clicked();

    void on_authorizationButton_clicked();

private:
    Ui::Authorization *ui;
};

#endif // AUTHORIZATION_H
