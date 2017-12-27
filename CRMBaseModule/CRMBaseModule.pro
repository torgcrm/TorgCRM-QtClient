QT       += core gui

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
    about.cpp \
    globalobject.cpp

HEADERS += \
        torgcrmmain.h \
    loginwindow.h \
    about.h \
    globalobject.h

FORMS += \
        torgcrmmain.ui \
    loginwindow.ui \
    about.ui

RESOURCES += \
    icons.qrc
