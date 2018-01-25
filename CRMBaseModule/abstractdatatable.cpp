#include "abstractdatatable.h"

using namespace CRMUi;

AbstractDataTable::AbstractDataTable(QWidget *parent):
    QWidget(parent)
{
    contextMenu = new QMenu();
    createNewAction = new QAction(tr("New"));
    editSelectedAction = new QAction(tr("Edit"));
    deleteSelectedAction = new QAction(tr("Delete"));

    connect(createNewAction, SIGNAL(triggered()), this, SLOT(createNewTriggeredSlot()));
    connect(editSelectedAction, SIGNAL(triggered()), this, SLOT(editSelectedTriggeredSlot()));
    connect(deleteSelectedAction, SIGNAL(triggered()), this,  SLOT(deleteSelectedTriggeredSlot()));

    contextMenu->addAction(createNewAction);
    contextMenu->addAction(editSelectedAction);
    contextMenu->addAction(deleteSelectedAction);
}

AbstractDataTable::~AbstractDataTable()
{
    delete contextMenu;
}
