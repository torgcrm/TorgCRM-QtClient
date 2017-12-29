#include "torgcrmmain.h"
#include "ui_torgcrmmain.h"
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QIcon>
#include <ctreeitem.h>

TorgCRMMain::TorgCRMMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TorgCRMMain)
{
    ui->setupUi(this);
    qDebug() << "Main window was opened successfuly.";
    globalObject = GLobalObject::getInstance();

    ui->leftMenuFrame->layout()->setAlignment(Qt::AlignTop);
    ui->rightContentFrame->layout()->setAlignment(Qt::AlignTop);

    QLineEdit *toolBarSearchInput = new QLineEdit;
    QPushButton *searchToolbarBtn = new QPushButton;
    searchToolbarBtn->setText(tr("Search"));
    searchToolbarBtn->setIcon(QIcon(":/icons/Icons/search.svg"));

    ui->searchToolBar->addWidget(toolBarSearchInput);
    ui->searchToolBar->addWidget(searchToolbarBtn);

    CTreeItem *crmItem = new CTreeItem("crmCode", "CRM");
    ui->mainMenu->addTopLevelItem(crmItem);

    CTreeItem *customersItem = new CTreeItem("customersCode", "Customers", ":/icons/Icons/customers.ico");
    crmItem->addChild(customersItem);
}

TorgCRMMain::~TorgCRMMain()
{
    delete ui;
}

void TorgCRMMain::on_mainMenu_itemClicked(QTreeWidgetItem *item)
{
    qDebug() << static_cast<CTreeItem *>(item)->getItemCode();
}
