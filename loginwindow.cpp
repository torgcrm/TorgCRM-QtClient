#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "about.h"
#include "torgcrmmain.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
    delete aboutDialog;
    delete torgCrmMainWindow;
}

/**
 * @brief LoginWindow::on_cancelBtn_clicked
 * When the close button was pushed
 */
void LoginWindow::on_cancelBtn_clicked()
{
    exit(0);
}

/**
 * @brief LoginWindow::on_loginBtn_clicked
 * When login button clicked. Authorize in application.
 */
void LoginWindow::on_loginBtn_clicked()
{
    torgCrmMainWindow = new TorgCRMMain(this);
    torgCrmMainWindow->show();
    this->hide();
}

/**
 * @brief LoginWindow::on_actionClose_triggered
 * Close application, when the close action triggered
 */
void LoginWindow::on_actionClose_triggered()
{
    qDebug("Triggered close action.");
    exit(0);
}

/**
 * @brief LoginWindow::on_actionAbout_triggered
 * Show about window
 */
void LoginWindow::on_actionAbout_triggered()
{
    qDebug("Triggered about action.");
    aboutDialog = new About(this);
    aboutDialog->setModal(true);
    aboutDialog->exec();
}
