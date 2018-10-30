#ifndef ADD_CARD_H
#define ADD_CARD_H

#include <QDialog>

namespace Ui {
class AddCard;
}

class AddCard : public QDialog
{
    Q_OBJECT

public:
    explicit AddCard(QWidget *parent = 0);
    ~AddCard();

private slots:
    void on_cancel_button_clicked();

    void on_add_card_button_clicked();

private:
    Ui::AddCard *ui;
};

#endif // ADD_CARD_H
