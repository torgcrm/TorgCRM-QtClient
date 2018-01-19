#include <QTableWidgetItem>

#include "customerdatawidget.h"
#include "ui_customerdatawidget.h"
#include "customer.h"

using namespace CRMUi;

CustomerDataWidget::CustomerDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerDataWidget)
{
    ui->setupUi(this);
    ui->customerDataTable->setSelectionBehavior(QAbstractItemView::SelectRows);
}

CustomerDataWidget::CustomerDataWidget(QWidget *parent, QJsonDocument *doc) :
    QWidget(parent),
    ui(new Ui::CustomerDataWidget)
{
    ui->setupUi(this);
    ui->customerDataTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->customerDataTable->setContextMenuPolicy(Qt::CustomContextMenu);

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
}
