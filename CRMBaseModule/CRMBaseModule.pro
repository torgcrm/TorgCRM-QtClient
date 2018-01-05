QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TorgCRM
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += ../CRMModels
INCLUDEPATH += ../CRMCommons

LIBS += -L$$OUT_PWD/../CRMCommons -lCRMCommons
LIBS += -L$$OUT_PWD/../CRMModels -lCRMModels

SOURCES += \
        main.cpp \
        torgcrmmain.cpp \
    loginwindow.cpp \
    taskdialog.cpp \
    customersearchdialog.cpp \
    customerdialog.cpp \
    aboutdialog.cpp \
    customerdatawidget.cpp

HEADERS += \
        torgcrmmain.h \
    loginwindow.h \
    taskdialog.h \
    customersearchdialog.h \
    customerdialog.h \
    aboutdialog.h \
    customerdatawidget.h

FORMS += \
        torgcrmmain.ui \
    loginwindow.ui \
    taskdialog.ui \
    customersearchdialog.ui \
    customerdialog.ui \
    aboutdialog.ui \
    customerdatawidget.ui

RESOURCES += \
    icons.qrc
