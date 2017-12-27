#include "ctreeitem.h"
#include <QIcon>

CTreeItem::CTreeItem(QString itemCode, QString title) : QTreeWidgetItem()
{
    this->itemCode = itemCode;
    this->setText(0, title);
}

CTreeItem::CTreeItem(QString itemCode, QString title, QString icon)
{
    this->itemCode = itemCode;
    this->setText(0, title);
    this->setIcon(0, QIcon(icon));
}

QString CTreeItem::getItemCode()
{
    return itemCode;
}
