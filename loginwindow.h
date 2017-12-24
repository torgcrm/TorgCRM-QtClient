#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "about.h"
#include "torgcrmmain.h"
#include "globalobject.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_cancelBtn_clicked();
    void on_loginBtn_clicked();
    void on_actionClose_triggered();
    void on_actionAbout_triggered();

private:
    Ui::LoginWindow *ui;
    About *aboutDialog;
    TorgCRMMain *torgCrmMainWindow;
    GLobalObject *globalObject;

signals:
    void loginSuccess(QString login, QString token);
};

#endif // LOGINWINDOW_H
