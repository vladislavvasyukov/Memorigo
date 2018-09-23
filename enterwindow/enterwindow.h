#ifndef ENTERWINDOW_H
#define ENTERWINDOW_H

#include <QMainWindow>

namespace Ui {
class EnterWindow;
}

class EnterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EnterWindow(QWidget *parent = 0);
    ~EnterWindow();

private slots:
    void on_registrationButon_clicked();

    void on_authorizationButton_clicked();

private:
    Ui::EnterWindow *ui;
};

#endif // ENTERWINDOW_H
