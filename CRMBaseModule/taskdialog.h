#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include <QDebug>

#include "task.h"
#include "cjsonworker.h"

namespace Ui {
class TaskDialog;
}

namespace CRMUi {
    class TaskDialog : public QDialog
    {
        Q_OBJECT

    public:
        explicit TaskDialog(QWidget *parent = 0);
        ~TaskDialog();

    private:
        Ui::TaskDialog *ui;
        CRMCommons::CJsonWorker *cJsonWorker;

    private slots:
        void onRejectDialog();
        void onAcceptDialog();
    };
}
#endif // TASKDIALOG_H
