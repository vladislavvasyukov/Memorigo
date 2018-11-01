#ifndef ADD_CATEGORY_H
#define ADD_CATEGORY_H

#include <QDialog>

namespace Ui {
class AddCategory;
}

class AddCategory : public QDialog
{
    Q_OBJECT

public:
    explicit AddCategory(QWidget *parent = 0);
    ~AddCategory();
    QString user_id;

private slots:
    void on_create_category_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::AddCategory *ui;
};

#endif // ADD_CATEGORY_H
