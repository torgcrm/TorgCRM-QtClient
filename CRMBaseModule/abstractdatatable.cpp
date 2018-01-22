#include "abstractdatatable.h"

using namespace CRMUi;

AbstractDataTable::AbstractDataTable(QWidget *parent):
    QWidget(parent)
{
    contextMenu = new QMenu();
    contextMenu->addAction("Edit");
    contextMenu->addAction("Delete");
}

AbstractDataTable::~AbstractDataTable()
{
    delete contextMenu;
}
