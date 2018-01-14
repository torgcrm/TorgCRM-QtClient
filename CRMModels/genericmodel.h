#ifndef GENERICMODEL_H
#define GENERICMODEL_H

#include <QObject>

namespace CRMModels {
    class GenericModel : public QObject {
        Q_OBJECT
    public:
        int getId() const;
        void setId(int value);

    private:
        int id;
    };
}

#endif // GENERICMODEL_H
