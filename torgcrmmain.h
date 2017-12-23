#ifndef TORGCRMMAIN_H
#define TORGCRMMAIN_H

#include <QMainWindow>

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
};

#endif // TORGCRMMAIN_H
