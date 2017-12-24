#include "globalobject.h"
#include <QDebug>

GLobalObject *GLobalObject::getInstance()
{
    if (!instance) {
        instance = new GLobalObject();
    }
    return instance;
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


