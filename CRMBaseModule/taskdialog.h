#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(QWidget *parent = 0);
    ~TaskDialog();

private:
    Ui::TaskDialog *ui;

private slots:
    void onRejectDialog();
    void onAcceptDialog();
};

#endif // TASKDIALOG_H
