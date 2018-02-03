#ifndef CUSTOMERDATAWIDGET_H
#define CUSTOMERDATAWIDGET_H

#include <QWidget>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonArray>
#include <QMenu>

#include "abstractdatatable.h"
#include "cjsonworker.h"
#include "customer.h"

namespace Ui {
class CustomerDataWidget;
}

namespace CRMUi {
    class CustomerDataWidget : public AbstractDataTable
    {
        Q_OBJECT

    public:
        explicit CustomerDataWidget(QWidget *parent, QJsonDocument *doc);
        ~CustomerDataWidget();

    private:
        Ui::CustomerDataWidget *ui;
        CRMCommons::CJsonWorker *cJsonWorker;
    public slots:
        void onTableDataModelClicked(const QModelIndex &index);
        void customContextMenuRequested(const QPoint &point);

    protected slots:
        void createNewTriggeredSlot();
        void editSelectedTriggeredSlot();
        void deleteSelectedTriggeredSlot();
        void onCustomerSavedSlot(CRMModels::Customer *customer);
        void onCustomerDeletedSlot(QNetworkReply *reply);
        void onCustomerGetByIdSlot(CRMModels::Customer *customer);
    };
}

#endif // CUSTOMERDATAWIDGET_H
