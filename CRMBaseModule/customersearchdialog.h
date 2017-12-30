#ifndef CUSTOMERSEARCH_H
#define CUSTOMERSEARCH_H

#include <QDialog>

namespace Ui {
class CustomerSearchDialog;
}

class CustomerSearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerSearchDialog(QWidget *parent = 0);
    ~CustomerSearchDialog();

private:
    Ui::CustomerSearchDialog *ui;
};

#endif // CUSTOMERSEARCH_H
