#include "cglobalobject.h"

using namespace CRMCommons;

static GLobalObject *_cGlobalObject = NULL;

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
    qDebug() << "Setting up token...";
    qDebug() << QString("Token for login %1 was set in: %2")
                .arg(login)
                .arg(token);
    this->token = token;
}


