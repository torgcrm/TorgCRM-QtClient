#include "loginwindow.h"
#include "ui_loginwindow.h"

using namespace CRMUi;
using namespace CRMCommons;

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    globalObject = GLobalObject::getInstance();
    connect (this, &LoginWindow::loginSuccess, globalObject,
             &GLobalObject::loginSuccess);

    ui->setupUi(this);
    ui->logoLabel->setScaledContents(true);
    ui->logoLabel->setPixmap(QPixmap(":/icons/Icons/logo.png"));
    this->setFixedSize(469, 191);

    worker = CJsonWorker::getInstance();
    connect (worker, SIGNAL(onAuthenticateFinished(QNetworkReply*)),
                           this, SLOT(onAuthenticateFinished(QNetworkReply*)));

}

LoginWindow::~LoginWindow()
{
    delete ui;
    delete aboutDialog;
    delete torgCrmMainWindow;
}

void LoginWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    if (QMessageBox::Yes == QMessageBox::question(this, tr("Close Confirmation?"),
                          tr("Are you sure you want to exit?"), QMessageBox::Yes|QMessageBox::No))
    {
        exit(0);
    }
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
    qDebug() << "Trying to login...";
    QString login = ui->userNameInput->text();
    QString password = ui->passwordInput->text();

    worker->authenticate(login, password);
}

/**
 * @brief LoginWindow::on_actionClose_triggered
 * Close application, when the close action triggered
 */
void LoginWindow::on_actionClose_triggered()
{
    qDebug("Triggered close action.");
    close();
}

/**
 * @brief LoginWindow::on_actionAbout_triggered
 * Show about window
 */
void LoginWindow::on_actionAbout_triggered()
{
    qDebug("Triggered about action.");
    aboutDialog = new AboutDialog(this);
    aboutDialog->setModal(true);
    aboutDialog->exec();
}

void LoginWindow::onAuthenticateFinished(QNetworkReply *reply)
{
    qDebug() << "Checking server authentication status...";
    if (!reply->error()) {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject obj = doc.object();
        QString token = obj.value("id_token").toString();
        emit loginSuccess(ui->userNameInput->text(), token);

        torgCrmMainWindow = new TorgCRMMain(this);
        torgCrmMainWindow->show();
        this->hide();
    } else {
        qDebug() << "Authentication faild.";
        QMessageBox::warning(this, "Authentication Error", "Sorry, username or password was wrong.");
    }
}
