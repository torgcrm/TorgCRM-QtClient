#ifndef CTREEITEM_H
#define CTREEITEM_H

#include <QTreeWidgetItem>

class CTreeItem : public QTreeWidgetItem
{
private:
    QString itemCode;
public:
    CTreeItem(QString itemCode, QString title);
    CTreeItem(QString itemCode, QString title, QString icon);
    QString getItemCode();
};

#endif // CTREEITEM_H
