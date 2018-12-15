#include "QStandardItemModel"
#include "QMessageBox"
#include "education.h"
#include "QListView"
#include "QDebug"
#include "QSqlQuery"
#include "QVBoxLayout"
#include "QPushButton"
#include "ui_education.h"
#include "add_card/add_card.h"
#include "add_category/add_category.h"

Education::Education(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Education)
{
    ui->setupUi(this);
    this->setupDecksList();
}

void Education::setupDecksList()
{
    QListView *decksList = new QListView(this);

    QStandardItemModel *model = new QStandardItemModel();
    QStandardItem *item;

    QSqlQuery query;
    query.prepare("SELECT title FROM decks WHERE user_id=2");
    query.exec();


    QString title = "";

    int decks_count = 0;
    while(query.next()) {
        title = query.value(0).toString();
        item = new QStandardItem(title);
        model->appendRow(item);
        decks_count++;
    }

    decksList->setModel(model);
    decksList->resize(250, decks_count * 18);
    connect(decksList, SIGNAL(clicked(QModelIndex)), SLOT(on_decksList_clicked(QModelIndex)));
    ui->verticalLayout->addWidget(decksList);
}

Education::~Education()
{
    delete ui;
}

void Education::on_add_card_button_clicked()
{
    AddCard add_card_window;
    add_card_window.user_id = this->user_id;
    add_card_window.setModal(true);
    add_card_window.exec();
}

void Education::on_add_category_button_clicked()
{
    AddCategory add_category_window;
    add_category_window.user_id = this->user_id;
    add_category_window.setModal(true);
    add_category_window.exec();
}

void Education::on_decksList_clicked(const QModelIndex &index)
{
    QString deck = index.data(Qt::DisplayRole).toString();

    QSqlQuery query;
    query.prepare("select c.id, c.question, c.answer, d.title from cards c inner join decks d on c.deck_id=d.id where d.title=:deck");
    query.bindValue(":deck", deck);
    query.exec();

    QString title = "TT";

    while(query.next()) {
        title += query.value(0).toString();
        title += query.value(1).toString();
        title += query.value(2).toString();
        title += query.value(3).toString();
    }
    qDebug() << ui->verticalLayout->count();
    while(ui->verticalLayout->count())
    {
        QLayoutItem * item = ui->verticalLayout->itemAt(0);
        ui->verticalLayout->removeItem(item);
        ui->verticalLayout->removeWidget(item->widget());
        delete item;
        delete item->widget();
        ui->verticalLayout->update();
    }
    ui->shadow->setText(deck);
    ui->temp_label->setText("Поздравляем! Вы завершили эту колоду на текущий момент!");
//    QVBoxLayout *layout = new QVBoxLayout(this);
//    QLabel *lbl = new QLabel("Поздравляем! Вы завершили эту колоду на текущий момент!" , this);
//    layout->addWidget(lbl);


//    QPushButton *but = new QPushButton(this);
//    but->setText(QString('QUIT'));
//    ui->verticalLayout->addWidget(but);
}
