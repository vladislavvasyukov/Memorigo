#ifndef EDUCATION_H
#define EDUCATION_H

#include <QDialog>

namespace Ui {
class Education;
}

class Education : public QDialog
{
    Q_OBJECT

public:
    explicit Education(QWidget *parent = 0);
    ~Education();
    QString user_id;

private slots:
    void setupDecksList();

    void on_add_card_button_clicked();

    void on_add_category_button_clicked();

    void on_decksList_clicked(const QModelIndex &index);

    void on_all_categories_clicked();

private:
    Ui::Education *ui;
};

#endif // EDUCATION_H
