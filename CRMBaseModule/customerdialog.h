#ifndef CUSTOMERDIALOG_H
#define CUSTOMERDIALOG_H

#include <QDialog>
#include <QDebug>

#include "customer.h"
#include "cjsonworker.h"
#include "cdialogmode.h"

namespace Ui {
class CustomerDialog;
}

namespace CRMUi {
class CustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerDialog(QWidget *parent = 0);
    explicit CustomerDialog(int mode,CRMModels::Customer *customer = 0, QWidget *parent = 0);
    ~CustomerDialog();

protected:
    void setup();

private slots:
    void dialogAccepted();
    void dialogRejected();

private:
    Ui::CustomerDialog *ui;
    int mode;
    CRMCommons::CJsonWorker *cJsonWorker;
    CRMModels::Customer *customer;
};
}
#endif // CUSTOMERDIALOG_H
