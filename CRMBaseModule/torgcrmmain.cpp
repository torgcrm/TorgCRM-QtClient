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
#include <QTableView>
#include <QLabel>
#include <QVBoxLayout>

#include "ctreeitem.h"
#include "customersearchdialog.h"
#include "aboutdialog.h"
#include "taskdialog.h"
#include "customerdatawidget.h"
#include "customerdialog.h"

TorgCRMMain::TorgCRMMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TorgCRMMain)
{
    ui->setupUi(this);
    qDebug() << "Main window was opened successfuly.";
    globalObject = GLobalObject::getInstance();
    cJsonWorker = CJsonWorker::getInstance();

    connect(cJsonWorker, &CJsonWorker::onMenuLoadFinished, this, &TorgCRMMain::onMainMenuDataLoadFinished);
    connect(cJsonWorker, &CJsonWorker::onCustomersLoadFinished, this, &TorgCRMMain::onCustomersLoadFinished);
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

int TorgCRMMain::getTabByName(QString tabName)
{
    int tabsCount = ui->mainCRMTabWidget->count();
    for (int i = 0; i < tabsCount; i ++) {
        QString tabText = ui->mainCRMTabWidget->tabText(i).replace("&", "");
        if (tabText.compare(tabName) == 0) {
            return i;
        }
    }
    return -1;
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
            cJsonWorker->getAllCustomers();
        } else {
            ui->mainCRMTabWidget->setCurrentIndex(this->getTabByName(cTreeItem->text(index)));
        }
    }

    /** Tasks **/
    if (QString::compare(TASKS_MENU, cTreeItem->getItemCode(), Qt::CaseInsensitive) == 0) {
        QFrame *frame = new QFrame();
        if (!checkExistingTab(index, cTreeItem)) {
            int tabIndex = ui->mainCRMTabWidget->addTab(frame, cTreeItem->text(index));
            ui->mainCRMTabWidget->setCurrentIndex(tabIndex);
        } else {
            ui->mainCRMTabWidget->setCurrentIndex(this->getTabByName(cTreeItem->text(index)));
        }
    }

    /** Dashboard **/
    if (QString::compare(DASHBOARD_MENU, cTreeItem->getItemCode(), Qt::CaseInsensitive) == 0) {
        QFrame *frame = new QFrame();
        if (!checkExistingTab(index, cTreeItem)) {
            int tabIndex = ui->mainCRMTabWidget->addTab(frame, cTreeItem->text(index));
            ui->mainCRMTabWidget->setCurrentIndex(tabIndex);
        } else {
            ui->mainCRMTabWidget->setCurrentIndex(this->getTabByName(cTreeItem->text(index)));
        }
    }

}

void TorgCRMMain::onMainMenuDataLoadFinished(QNetworkReply *reply)
{
    if (!reply->error()) {
        qDebug() << "TorgCRMForm menu was loaded...";

        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
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

void TorgCRMMain::onCustomersLoadFinished(QNetworkReply *reply)
{
    if (!reply->error()) {
        qDebug() << "TorgCRMForm customers was loaded...";
        QFrame *tabWidget = qobject_cast<QFrame *>(ui->mainCRMTabWidget->widget(this->getTabByName("Customers")));
        if (tabWidget->children().size() < 1) {
            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            CustomerDataWidget *customerDataWidget = new CustomerDataWidget(tabWidget);

            QVBoxLayout *vBoxLayout = new QVBoxLayout;
            tabWidget->setLayout(vBoxLayout);
            vBoxLayout->addWidget(customerDataWidget);

            foreach (QJsonValue topLevelVal, doc.array()) {
                QJsonObject topLevelObject = topLevelVal.toObject();
                qDebug() << topLevelObject;
            }
        }
    } else {
        qDebug() << "Error while loading Customers.";
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
