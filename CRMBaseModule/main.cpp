#include <QApplication>
#include <QLoggingCategory>

#include "loginwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CRMUi::LoginWindow login;
    login.show();

    return a.exec();
}
