#ifndef TORGCRMMAIN_H
#define TORGCRMMAIN_H

#include <QMainWindow>
#include "globalobject.h"

namespace Ui {
class TorgCRMMain;
}

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
};

#endif // TORGCRMMAIN_H
