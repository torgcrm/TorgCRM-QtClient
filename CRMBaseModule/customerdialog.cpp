#include "customerdialog.h"
#include "ui_customerdialog.h"

CustomerDialog::CustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    this->setFixedSize(QSize(800, 600));
}

CustomerDialog::~CustomerDialog()
{
    delete ui;
}

void CustomerDialog::on_bottomButtons_accepted()
{

}

void CustomerDialog::on_bottomButtons_rejected()
{
    this->close();
}
