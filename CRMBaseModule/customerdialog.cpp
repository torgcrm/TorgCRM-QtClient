#include "customerdialog.h"
#include "ui_customerdialog.h"

CustomerDialog::CustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    ui->setupUi(this);
}

CustomerDialog::~CustomerDialog()
{
    delete ui;
}
