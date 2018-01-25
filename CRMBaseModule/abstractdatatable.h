#ifndef ABSTRACTDATATABLE_H
#define ABSTRACTDATATABLE_H

#include <QMenu>

namespace CRMUi {
    class AbstractDataTable : public QWidget
    {
        Q_OBJECT
    public:
        AbstractDataTable(QWidget *parent = 0);
        ~AbstractDataTable();
    protected:
        QMenu *contextMenu;
        QAction *createNewAction;
        QAction *editSelectedAction;
        QAction *deleteSelectedAction;
    public slots:
        virtual void createNewTriggeredSlot() = 0;
        virtual void editSelectedTriggeredSlot() = 0;
        virtual void deleteSelectedTriggeredSlot() = 0;
    };
}

#endif // ABSTRACTDATATABLE_H
