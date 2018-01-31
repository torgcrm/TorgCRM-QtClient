#include "customer.h"

using namespace CRMModels;

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

int Customer::getTypeId() const
{
    return typeId;
}

void Customer::setTypeId(int value)
{
    typeId = value;
}

void Customer::fromJSON(QByteArray json)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(json);
    QJsonObject object = jsonDoc.object();
    setId(object.value(JSON_CSTMR_ID).toInt());
    setFullName(object.value(JSON_CSTMR_FULLNAME).toString());
    setEmail(object.value(JSON_CSTMR_EMAIL).toString());
    setComment(object.value(JSON_CSTMR_COMMENT).toString());
    setFax(object.value(JSON_CSTMR_FAX).toString());
    setPhone(object.value(JSON_CSTMR_PHONE).toString());
    setSource(object.value(JSON_CSTMR_SOURCE).toString());
    setTypeId(object.value(JSON_CSTMR_TYPEID).toInt());
}
