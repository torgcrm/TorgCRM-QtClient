#include "customer.h"

using namespace CModels;

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
