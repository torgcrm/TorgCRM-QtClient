#include "torgcrmmain.h"
#include "ui_torgcrmmain.h"

TorgCRMMain::TorgCRMMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TorgCRMMain)
{
    ui->setupUi(this);
}

TorgCRMMain::~TorgCRMMain()
{
    delete ui;
}
