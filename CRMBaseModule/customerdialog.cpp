#include "customerdialog.h"
#include "ui_customerdialog.h"

using namespace CRMUi;
using namespace CRMCommons;

void CustomerDialog::setup()
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    this->setFixedSize(QSize(800, 600));
    cJsonWorker = CJsonWorker::getInstance();
}

CustomerDialog::CustomerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    setup();
}

CustomerDialog::CustomerDialog(int mode, QWidget *parent):
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    setup();
    this->mode = mode;
}

CustomerDialog::~CustomerDialog()
{
    delete ui;
}

void CustomerDialog::dialogAccepted()
{
    qDebug() << "Trying to save customer";
    CModels::Customer customer;
    customer.setTypeId(0);
    customer.setFullName(ui->customerFullNameInput->text());
    customer.setPhone(ui->customerPhoneNumberInput->text());
    customer.setEmail(ui->customerEmailInput->text());
    customer.setFax(ui->customerFaxInput->text());
    customer.setSource(ui->customerSourceInput->text());
    customer.setComment(ui->customerCommentsTextInput->toPlainText());

    cJsonWorker->saveCustomer(&customer);
}

void CustomerDialog::dialogRejected()
{
    qDebug() << "Close customer dialog...";
    this->close();
}
