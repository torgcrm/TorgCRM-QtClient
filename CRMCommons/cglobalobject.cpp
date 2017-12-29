#include "cglobalobject.h"
#include <QDebug>

GLobalObject *GLobalObject::getInstance()
{
    if (!_cGlobalObject) {
        _cGlobalObject = new GLobalObject();
    }
    return _cGlobalObject;
}

QString GLobalObject::getToken()
{
    return token;
}

void GLobalObject::loginSuccess(QString login, QString token)
{
    qDebug() << login << token << endl;
    this->token = token;
}


