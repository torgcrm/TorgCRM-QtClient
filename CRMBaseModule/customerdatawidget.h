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
    public slots:
        void onTableDataModelClicked(const QModelIndex &index);
        void customContextMenuRequested(const QPoint &point);

    protected slots:
        void createNewTriggeredSlot();
        void editSelectedTriggeredSlot();
        void deleteSelectedTriggeredSlot();
    };
}

#endif // CUSTOMERDATAWIDGET_H
