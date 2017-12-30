#ifndef TASK_H
#define TASK_H

#include <QDialog>

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
};

#endif // TASK_H
