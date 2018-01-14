#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>

#include "cjsonworker.h"
#include "aboutdialog.h"
#include "torgcrmmain.h"
#include "cglobalobject.h"
#include "aboutdialog.h"
#include "torgcrmmain.h"

namespace Ui {
class LoginWindow;
}

namespace CRMUi {
/**
 * @brief The LoginWindow class. Login form
 */
class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

    void closeEvent(QCloseEvent * event);
private slots:
    void on_cancelBtn_clicked();
    void on_loginBtn_clicked();
    void on_actionClose_triggered();
    void on_actionAbout_triggered();
    void onAuthenticateFinished(QNetworkReply *reply);

private:
    Ui::LoginWindow *ui;
    AboutDialog *aboutDialog;
    TorgCRMMain *torgCrmMainWindow;
    CRMCommons::GLobalObject *globalObject;
    CRMCommons::CJsonWorker *worker;

signals:
    void loginSuccess(QString login, QString token);
};
}
#endif // LOGINWINDOW_H
