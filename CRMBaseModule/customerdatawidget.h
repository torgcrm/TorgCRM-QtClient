#ifndef CUSTOMERDATAWIDGET_H
#define CUSTOMERDATAWIDGET_H

#include <QWidget>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonArray>

namespace Ui {
class CustomerDataWidget;
}

class CustomerDataWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomerDataWidget(QWidget *parent = 0);
    explicit CustomerDataWidget(QWidget *parent, QJsonDocument *doc);
    ~CustomerDataWidget();

private:
    Ui::CustomerDataWidget *ui;
};

#endif // CUSTOMERDATAWIDGET_H
