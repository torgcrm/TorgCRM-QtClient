#ifndef CUSTOMER_H
#define CUSTOMER_H

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

private:
    Ui::CustomerDialog *ui;
};

#endif // CUSTOMER_H
