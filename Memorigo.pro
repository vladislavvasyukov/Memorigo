#-------------------------------------------------
#
# Project created by QtCreator 2018-09-22T15:42:44
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Memorigo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        enterwindow\enterwindow.cpp \
        registration\registration.cpp \
        authorization\authorization.cpp \
    education/education.cpp \
    add_card/add_card.cpp \
    add_category/add_category.cpp \
    base_combo_model.cpp

HEADERS += \
        enterwindow\enterwindow.h \
        registration\registration.h \
        authorization\authorization.h \
    education/education.h \
    add_card/add_card.h \
    add_category/add_category.h \
    base_combo_model.h

FORMS += \
        enterwindow\enterwindow.ui \
        registration\registration.ui \
        authorization\authorization.ui \
    education/education.ui \
    add_card/add_card.ui \
    add_category/add_category.ui
