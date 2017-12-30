QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TorgCRM
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += ../CRMCommons
LIBS += -L$$OUT_PWD/../CRMCommons -lCRMCommons

SOURCES += \
        main.cpp \
        torgcrmmain.cpp \
    loginwindow.cpp \
    taskdialog.cpp \
    customersearchdialog.cpp \
    customerdialog.cpp \
    aboutdialog.cpp

HEADERS += \
        torgcrmmain.h \
    loginwindow.h \
    taskdialog.h \
    customersearchdialog.h \
    customerdialog.h \
    aboutdialog.h

FORMS += \
        torgcrmmain.ui \
    loginwindow.ui \
    taskdialog.ui \
    customersearchdialog.ui \
    customerdialog.ui \
    aboutdialog.ui

RESOURCES += \
    icons.qrc
