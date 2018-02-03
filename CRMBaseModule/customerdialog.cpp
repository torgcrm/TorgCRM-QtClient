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

CustomerDialog::CustomerDialog(int mode, CRMModels::Customer *customer, QWidget *parent):
    QDialog(parent),
    ui(new Ui::CustomerDialog)
{
    setup();
    if (customer) {
        this->customer = customer;
        this->ui->customerFullNameInput->setText(customer->getFullName());
        this->ui->customerPhoneNumberInput->setText(customer->getPhone());
        this->ui->customerEmailInput->setText(customer->getEmail());
        this->ui->customerFaxInput->setText(customer->getFax());
        this->ui->customerSourceInput->setText(customer->getSource());
        this->ui->customerCommentsTextInput->setText(customer->getComment());
    }
    this->mode = mode;
}

CustomerDialog::~CustomerDialog()
{
    delete ui;
}

void CustomerDialog::dialogAccepted()
{
    qDebug() << "Trying to save customer";
    CRMModels::Customer customer;
    customer.setTypeId(0);
    customer.setFullName(ui->customerFullNameInput->text());
    customer.setPhone(ui->customerPhoneNumberInput->text());
    customer.setEmail(ui->customerEmailInput->text());
    customer.setFax(ui->customerFaxInput->text());
    customer.setSource(ui->customerSourceInput->text());
    customer.setComment(ui->customerCommentsTextInput->toPlainText());

    if (mode == CRMCommons::DialogMode::EDITMODE) {
        customer.setId(this->customer->getId());
        cJsonWorker->updateCustomer(&customer);
    } else if (mode == CRMCommons::DialogMode::CRTMODE) {
        cJsonWorker->saveCustomer(&customer);
    }
}

void CustomerDialog::dialogRejected()
{
    qDebug() << "Close customer dialog...";
    this->close();
}
