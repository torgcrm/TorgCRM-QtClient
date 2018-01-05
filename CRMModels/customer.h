#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

#include "genericmodel.h"

namespace CModels {
class Customer;
}

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

#endif // CUSTOMER_H

QString Customer::getFullName() const
{
    return fullName;
}

void Customer::setFullName(const QString &value)
{
    fullName = value;
}

QString Customer::getPhone() const
{
return phone;
}

void Customer::setPhone(const QString &value)
{
phone = value;
}

QString Customer::getEmail() const
{
return email;
}

void Customer::setEmail(const QString &value)
{
email = value;
}

QString Customer::getFax() const
{
return fax;
}

void Customer::setFax(const QString &value)
{
fax = value;
}

QString Customer::getSource() const
{
return source;
}

void Customer::setSource(const QString &value)
{
source = value;
}

QString Customer::getComment() const
{
return comment;
}

void Customer::setComment(const QString &value)
{
comment = value;
}
