#ifndef TORGCRMMAIN_H
#define TORGCRMMAIN_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QCloseEvent>
#include <QMessageBox>
#include <QNetworkReply>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QIcon>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QTableView>
#include <QLabel>
#include <QVBoxLayout>

#include "cglobalobject.h"
#include "cjsonworker.h"
#include "ctreeitem.h"
#include "dialogmodes.h"
#include "customersearchdialog.h"
#include "aboutdialog.h"
#include "taskdialog.h"
#include "customerdatawidget.h"
#include "customerdialog.h"
#include "taskdatawidget.h"

#define CUSTOMERS_MENU "customers"
#define TASKS_MENU "tasks"
#define DASHBOARD_MENU "dashboard"
#define ORDERS_MENU "orders"

namespace Ui {
class TorgCRMMain;
}

namespace CRMUi {
/**
 * @brief The TorgCRMMain class
 */
class TorgCRMMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit TorgCRMMain(QWidget *parent = 0);
    ~TorgCRMMain();

    void closeEvent(QCloseEvent *event)
    {
        event->ignore();
        if (QMessageBox::Yes == QMessageBox::question(this, tr("Close Confirmation?"),
                              tr("Are you sure you want to exit?"), QMessageBox::Yes|QMessageBox::No))
        {
            exit(0);
        }
    }
private:
    Ui::TorgCRMMain *ui;
    CRMCommons::GLobalObject *globalObject;
    CRMCommons::CJsonWorker *cJsonWorker;

    void openTaskDialog();
    bool checkExistingTab(int index, CRMCommons::CTreeItem *cTreeItem);
    int getTabByName(QString tabName);
private slots:
    void on_mainMenu_itemClicked(QTreeWidgetItem *item, int index);
    void onMainMenuDataLoadFinished(QNetworkReply *reply);
    void onCustomersLoadFinished(QNetworkReply *reply);
    void on_actionClose_triggered();
    void on_actionAdd_New_triggered();
    void on_actionSearch_triggered();
    void on_actionAbout_triggered();
    void on_actionNew_Task_triggered();
    void on_actionNew_Meeting_triggered();
    void on_actionNew_Email_triggered();
    void on_actionCall_Task_triggered();
    void on_mainCRMTabWidget_tabCloseRequested(int index);
    void onTasksLoadFinished(QNetworkReply *reply);
};
}
#endif // TORGCRMMAIN_H
