#include "torgcrmmain.h"
#include "ui_torgcrmmain.h"
#include <QDebug>

TorgCRMMain::TorgCRMMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TorgCRMMain)
{
    GLobalObject *globalObject = GLobalObject::getInstance();
    qDebug() << "Toke is: " << globalObject->getToken() << endl;
    ui->setupUi(this);
}

TorgCRMMain::~TorgCRMMain()
{
    delete ui;
}

void TorgCRMMain::loginSuccess(QString login, QString token)
{
    qDebug() << login << token << endl;
}
