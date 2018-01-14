#include "taskdatawidget.h"
#include "ui_taskdatawidget.h"

using namespace CRMUi;

TaskDataWidget::TaskDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskDataWidget)
{
    ui->setupUi(this);
}

TaskDataWidget::TaskDataWidget(QWidget *parent, QJsonDocument *doc):
    QWidget(parent),
    ui(new Ui::TaskDataWidget)
{
    ui->setupUi(this);
}

TaskDataWidget::~TaskDataWidget()
{
    delete ui;
}
