#ifndef CUSTOMERDIALOG_H
#define CUSTOMERDIALOG_H

#include <QDialog>

namespace Ui {
class CustomerDialog;
}

class CustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerDialog(QWidget *parent = 0);
    ~CustomerDialog();

private slots:
    void on_bottomButtons_accepted();

    void on_bottomButtons_rejected();

private:
    Ui::CustomerDialog *ui;
};

#endif // CUSTOMERDIALOG_H
