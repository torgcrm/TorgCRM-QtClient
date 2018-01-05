#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

#include "genericmodel.h"

namespace CModels {
    class Customer : GenericModel {
    public:
        QString getFullName() const;
        void setFullName(const QString &value);

        QString getPhone() const;
        void setPhone(const QString &value);

        QString getEmail() const;
        void setEmail(const QString &value);

        QString getFax() const;
        void setFax(const QString &value);

        QString getSource() const;
        void setSource(const QString &value);

        QString getComment() const;
        void setComment(const QString &value);

    private:
        QString fullName;
        QString phone;
        QString email;
        QString fax;
        QString source;
        QString comment;
    };
}

#endif // CUSTOMER_H
