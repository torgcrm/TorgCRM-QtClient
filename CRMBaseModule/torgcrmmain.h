#ifndef TORGCRMMAIN_H
#define TORGCRMMAIN_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QCloseEvent>
#include <QMessageBox>
#include <QNetworkReply>

#include "cglobalobject.h"
#include "cjsonworker.h"

namespace Ui {
class TorgCRMMain;
}

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
    GLobalObject *globalObject;
    CJsonWorker *cJsonWorker;

private slots:
    void on_mainMenu_itemClicked(QTreeWidgetItem *item);
    void onMainMenuDataLoadFinished(QNetworkReply *reply);
};

#endif // TORGCRMMAIN_H
