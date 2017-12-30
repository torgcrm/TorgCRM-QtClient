#include "torgcrmmain.h"
#include "ui_torgcrmmain.h"
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QIcon>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include "ctreeitem.h"

TorgCRMMain::TorgCRMMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TorgCRMMain)
{
    ui->setupUi(this);
    qDebug() << "Main window was opened successfuly.";
    globalObject = GLobalObject::getInstance();
    cJsonWorker = CJsonWorker::getInstance();

    connect(cJsonWorker, &CJsonWorker::onMenuLoadFinished, this, &TorgCRMMain::onMainMenuDataLoadFinished);
    cJsonWorker->getAllMenus(); // load menu from server

    ui->leftMenuFrame->layout()->setAlignment(Qt::AlignTop);
    ui->rightContentFrame->layout()->setAlignment(Qt::AlignTop);

    QLineEdit *toolBarSearchInput = new QLineEdit;
    QPushButton *searchToolbarBtn = new QPushButton;
    searchToolbarBtn->setText(tr("Search"));
    searchToolbarBtn->setIcon(QIcon(":/icons/Icons/search.svg"));

    ui->searchToolBar->addWidget(toolBarSearchInput);
    ui->searchToolBar->addWidget(searchToolbarBtn);
}

TorgCRMMain::~TorgCRMMain()
{
    delete ui;
}

void TorgCRMMain::on_mainMenu_itemClicked(QTreeWidgetItem *item)
{
    qDebug() << static_cast<CTreeItem *>(item)->getItemCode();
}

void TorgCRMMain::onMainMenuDataLoadFinished(QNetworkReply *reply)
{
    if (!reply->error()) {
        qDebug() << "TorgCRMForm initializing menu...";

        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        qDebug() << doc.isArray();
        foreach (QJsonValue topLevelVal, doc.array()) {
            QJsonObject topLevelObject = topLevelVal.toObject();
            CTreeItem *menuTopLevelItem = new CTreeItem(topLevelObject.value("code").toString(),
                                               topLevelObject.value("title").toString());
            ui->mainMenu->addTopLevelItem(menuTopLevelItem);
            foreach (QJsonValue item, topLevelObject.value("items").toArray()) {
                QJsonObject itemObject = item.toObject();
                CTreeItem *menuItem = new CTreeItem(itemObject.value("code").toString(),
                                                   itemObject.value("title").toString(),
                                                   itemObject.value("icon").toString());
                menuTopLevelItem->addChild(menuItem);
            }
        }
    } else {
        qDebug() << "Error while loading Menu.";
    }
}
