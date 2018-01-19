#include "taskdatawidget.h"
#include "ui_taskdatawidget.h"

using namespace CRMUi;

TaskDataWidget::TaskDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskDataWidget)
{
    ui->setupUi(this);
    setup();
}

TaskDataWidget::TaskDataWidget(QWidget *parent, QJsonDocument *doc):
    QWidget(parent),
    ui(new Ui::TaskDataWidget)
{
    ui->setupUi(this);
    setup();
}

TaskDataWidget::~TaskDataWidget()
{
    delete ui;
}

void TaskDataWidget::setup()
{
    qDebug() << "connect...";
    connect(ui->tasksDatatable, SIGNAL(clicked(QModelIndex)), this, SLOT(onTableDataModelClicked(QModelIndex)));
    connect(ui->tasksDatatable, SIGNAL(activated(QModelIndex)), this, SLOT(onTableDataModelClicked(QModelIndex)));
}

void TaskDataWidget::onTableDataModelClicked(const QModelIndex &index)
{
    qDebug() << "onTableDataModelClicked...";
}
