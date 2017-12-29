#ifndef TORGCRMMAIN_H
#define TORGCRMMAIN_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QCloseEvent>
#include <QMessageBox>

#include "cglobalobject.h"

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

public slots:
    void loginSuccess(QString login, QString token);
private slots:
    void on_mainMenu_itemClicked(QTreeWidgetItem *item);
};

#endif // TORGCRMMAIN_H
