#ifndef TASKDATAWIDGET_H
#define TASKDATAWIDGET_H

#include <QWidget>
#include <QJsonDocument>
#include <QDebug>
#include <QModelIndex>

namespace Ui {
class TaskDataWidget;
}

namespace CRMUi {
    class TaskDataWidget : public QWidget
    {
        Q_OBJECT
    public:
        explicit TaskDataWidget(QWidget *parent = 0);
        explicit TaskDataWidget(QWidget *parent, QJsonDocument *doc);
        ~TaskDataWidget();
    private:
        Ui::TaskDataWidget *ui;
        void setup();
    private slots:
        void onTableDataModelClicked(const QModelIndex &index);
    };
}
#endif // TASKDATAWIDGET_H
