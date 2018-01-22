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
    };
}

#endif // ABSTRACTDATATABLE_H
