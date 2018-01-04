#include "customerdatawidget.h"
#include "ui_customerdatawidget.h"

CustomerDataWidget::CustomerDataWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomerDataWidget)
{
    ui->setupUi(this);
}

CustomerDataWidget::~CustomerDataWidget()
{
    delete ui;
}
