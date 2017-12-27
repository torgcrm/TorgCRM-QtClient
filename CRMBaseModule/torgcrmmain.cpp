#include "torgcrmmain.h"
#include "ui_torgcrmmain.h"
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QIcon>

TorgCRMMain::TorgCRMMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TorgCRMMain)
{
    GLobalObject *globalObject = GLobalObject::getInstance();
    qDebug() << "Token is: " << globalObject->getToken() << endl;
    ui->setupUi(this);

    ui->leftMenuFrame->layout()->setAlignment(Qt::AlignTop);
    ui->rightContentFrame->layout()->setAlignment(Qt::AlignTop);

    QLineEdit *toolBarSearchInput = new QLineEdit;
    QPushButton *searchToolbarBtn = new QPushButton;
    searchToolbarBtn->setText(tr("Search"));
    searchToolbarBtn->setIcon(QIcon(":/icons/Icons/search.svg"));

    ui->searchToolBar->addWidget(toolBarSearchInput);
    ui->searchToolBar->addWidget(searchToolbarBtn);

    ui->mainMenu->header()->resize(QSize(200, 200));
}

TorgCRMMain::~TorgCRMMain()
{
    delete ui;
}

void TorgCRMMain::loginSuccess(QString login, QString token)
{
    qDebug() << login << token << endl;
}
