#ifndef TASKDATAWIDGET_H
#define TASKDATAWIDGET_H

#include <QWidget>
#include <QJsonDocument>

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
    };
}
#endif // TASKDATAWIDGET_H
