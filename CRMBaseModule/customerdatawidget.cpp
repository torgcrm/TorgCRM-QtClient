#include <QTableWidgetItem>

#include "customerdatawidget.h"
#include "ui_customerdatawidget.h"
#include "customer.h"

using namespace CRMUi;

CustomerDataWidget::CustomerDataWidget(QWidget *parent, QJsonDocument *doc) :
    AbstractDataTable(parent),
    ui(new Ui::CustomerDataWidget)
{
    ui->setupUi(this);
    cJsonWorker = CRMCommons::CJsonWorker::getInstance();

    ui->customerDataTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->customerDataTable->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->customerDataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->customerDataTable, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(onTableDataModelClicked(QModelIndex)));

    connect(ui->customerDataTable, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(customContextMenuRequested(QPoint)));


    int i = 0;
    foreach (QJsonValue topLevelVal, doc->array()) {
        QJsonObject topLevelObject = topLevelVal.toObject();
        qDebug() << topLevelObject;
        qDebug() << topLevelObject.value(JSON_CSTMR_FULLNAME);

        ui->customerDataTable->insertRow(i);
        ui->customerDataTable->setItem(i,0, new QTableWidgetItem(topLevelObject.value(JSON_CSTMR_ID).toVariant().toString()));
        ui->customerDataTable->setItem(i,1, new QTableWidgetItem(topLevelObject.value(JSON_CSTMR_FULLNAME).toString()));
        ui->customerDataTable->setItem(i,2, new QTableWidgetItem(topLevelObject.value(JSON_CSTMR_TYPEID).toVariant().toString()));
        ui->customerDataTable->setItem(i,3, new QTableWidgetItem(topLevelObject.value(JSON_CSTMR_EMAIL).toString()));
        ui->customerDataTable->setItem(i,4, new QTableWidgetItem(topLevelObject.value(JSON_CSTMR_PHONE).toString()));
        ui->customerDataTable->setItem(i,5, new QTableWidgetItem(topLevelObject.value(JSON_CSTMR_SOURCE).toString()));
        ui->customerDataTable->setItem(i,6, new QTableWidgetItem(topLevelObject.value(JSON_CSTMR_FAX).toString()));

        i++;
    }
}

CustomerDataWidget::~CustomerDataWidget()
{
    delete ui;
}

void CustomerDataWidget::onTableDataModelClicked(const QModelIndex &index)
{
    qDebug() << "Click on customer data table...";
}

void CustomerDataWidget::customContextMenuRequested(const QPoint &point)
{
    qDebug() << "Context menu...";
    qDebug() << "Selected row index: " << ui->customerDataTable->currentIndex().row();
    contextMenu->popup(ui->customerDataTable->viewport()->mapToGlobal(point));
}

void CustomerDataWidget::createNewTriggeredSlot()
{
    qDebug() << "Click on create new action";
}

void CustomerDataWidget::editSelectedTriggeredSlot()
{
    qDebug() << "Click on edit selected item";
    int selectedRow = ui->customerDataTable->currentIndex().row();
    QString customerId = ui->customerDataTable->item(selectedRow, 0)->data(0).toString();
}

void CustomerDataWidget::deleteSelectedTriggeredSlot()
{
    qDebug() << "Click on delete selected item";
    int selectedRow = ui->customerDataTable->currentIndex().row();
    QString customerId = ui->customerDataTable->item(selectedRow, 0)->data(0).toString();
    cJsonWorker->deleteCustomer(customerId.toInt());
}
