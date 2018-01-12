#include "taskdialog.h"
#include "ui_taskdialog.h"

TaskDialog::TaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);
}

TaskDialog::~TaskDialog()
{
    delete ui;
}

void TaskDialog::onRejectDialog()
{
    this->close();
}

void TaskDialog::onAcceptDialog()
{
    qDebug() << "Creating or updating task";
}
