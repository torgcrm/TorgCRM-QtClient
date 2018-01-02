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
#include "customerdialog.h"
#include "customersearchdialog.h"
#include "aboutdialog.h"
#include "taskdialog.h"

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

bool TorgCRMMain::checkExistingTab(int index, CTreeItem *cTreeItem)
{
    int tabsCount = ui->mainCRMTabWidget->count();
    for (int i = 0; i < tabsCount; i ++) {
        QString tabText = ui->mainCRMTabWidget->tabText(i).replace("&", "");
        if (tabText.compare(cTreeItem->text(index)) == 0) {
            return true;
        }
    }
    return false;
}

void TorgCRMMain::on_mainMenu_itemClicked(QTreeWidgetItem *item, int index)
{
    CTreeItem *cTreeItem = static_cast<CTreeItem *>(item);
    /** Customers **/
    if (QString::compare(CUSTOMERS_MENU, cTreeItem->getItemCode(), Qt::CaseInsensitive) == 0) {
        QFrame *frame = new QFrame();
        if (!checkExistingTab(index, cTreeItem)) {
            int tabIndex = ui->mainCRMTabWidget->addTab(frame, cTreeItem->text(index));
            ui->mainCRMTabWidget->setCurrentIndex(tabIndex);
        }
    }

    /** Tasks **/
    if (QString::compare(TASKS_MENU, cTreeItem->getItemCode(), Qt::CaseInsensitive) == 0) {
        QFrame *frame = new QFrame();
        if (!checkExistingTab(index, cTreeItem)) {
            int tabIndex = ui->mainCRMTabWidget->addTab(frame, cTreeItem->text(index));
            ui->mainCRMTabWidget->setCurrentIndex(tabIndex);
        }
    }

    /** Dashboard **/
    if (QString::compare(DASHBOARD_MENU, cTreeItem->getItemCode(), Qt::CaseInsensitive) == 0) {
        QFrame *frame = new QFrame();
        if (!checkExistingTab(index, cTreeItem)) {
            int tabIndex = ui->mainCRMTabWidget->addTab(frame, cTreeItem->text(index));
            ui->mainCRMTabWidget->setCurrentIndex(tabIndex);
        }
    }

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

void TorgCRMMain::on_actionClose_triggered()
{
    close();
}

void TorgCRMMain::on_actionAdd_New_triggered()
{
    CustomerDialog *customerDialog = new CustomerDialog(this);
    customerDialog->setModal(true);
    customerDialog->exec();
}

void TorgCRMMain::on_actionSearch_triggered()
{
    CustomerSearchDialog *customerSearchDialog = new CustomerSearchDialog(this);
    customerSearchDialog->setModal(true);
    customerSearchDialog->exec();
}

void TorgCRMMain::on_actionAbout_triggered()
{
    AboutDialog *aboutDialog = new AboutDialog(this);
    aboutDialog->setModal(true);
    aboutDialog->exec();
}

void TorgCRMMain::on_actionNew_Task_triggered()
{
    openTaskDialog();
}

void TorgCRMMain::on_actionNew_Meeting_triggered()
{
    openTaskDialog();
}

void TorgCRMMain::on_actionNew_Email_triggered()
{
    openTaskDialog();
}

void TorgCRMMain::on_actionCall_Task_triggered()
{
    openTaskDialog();
}

void TorgCRMMain::openTaskDialog() {
    TaskDialog *taskDialog = new TaskDialog(this);
    taskDialog->setModal(true);
    taskDialog->exec();
}

void TorgCRMMain::on_mainCRMTabWidget_tabCloseRequested(int index)
{
    ui->mainCRMTabWidget->removeTab(index);
}
