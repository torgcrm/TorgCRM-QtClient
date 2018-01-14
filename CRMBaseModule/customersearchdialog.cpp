#include "customersearchdialog.h"
#include "ui_customersearchdialog.h"

using namespace CRMUi;

CustomerSearchDialog::CustomerSearchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerSearchDialog)
{
    ui->setupUi(this);
}

CustomerSearchDialog::~CustomerSearchDialog()
{
    delete ui;
}
