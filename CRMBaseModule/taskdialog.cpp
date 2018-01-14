#include "taskdialog.h"
#include "ui_taskdialog.h"

using namespace CRMUi;
using namespace CRMCommons;

TaskDialog::TaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);
    cJsonWorker = CJsonWorker::getInstance();
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
    CModels::Task task;
    task.setTitle(ui->taskNameInput->text());
    task.setBeginDate(ui->startDateInput->dateTime());
    task.setEndDate(ui->finishDateInput->dateTime());
    task.setComment(ui->commentsInput->toPlainText());

    cJsonWorker->saveTask(&task);
}
