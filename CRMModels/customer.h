#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

#include "genericmodel.h"

#define JSON_CSTMR_FULLNAME   "fullname"
#define JSON_CSTMR_EMAIL      "email"
#define JSON_CSTMR_COMMENT    "comment"
#define JSON_CSTMR_FAX        "fax"
#define JSON_CSTMR_ID         "id"
#define JSON_CSTMR_PHONE      "phoneNumber"
#define JSON_CSTMR_SOURCE     "source"
#define JSON_CSTMR_TYPEID     "typeId"

namespace CRMModels {
    class Customer : public GenericModel {
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

        int getTypeId() const;
        void setTypeId(int value);

    private:
        QString fullName;
        QString phone;
        QString email;
        QString fax;
        QString source;
        QString comment;
        int typeId;
    };
}

#endif // CUSTOMER_H
