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

private:
    Ui::Education *ui;
};

#endif // EDUCATION_H
