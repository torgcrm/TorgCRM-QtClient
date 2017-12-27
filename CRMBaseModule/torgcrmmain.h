#ifndef TORGCRMMAIN_H
#define TORGCRMMAIN_H

#include <QMainWindow>
#include <QTreeWidget>

#include "globalobject.h"

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

private:
    Ui::TorgCRMMain *ui;

public slots:
    void loginSuccess(QString login, QString token);
private slots:
    void on_mainMenu_itemClicked(QTreeWidgetItem *item);
};

#endif // TORGCRMMAIN_H
