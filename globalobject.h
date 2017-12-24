#ifndef GLOBALOBJECT_H
#define GLOBALOBJECT_H

#include <QObject>

class GLobalObject : public QObject
{
public:
    static GLobalObject *getInstance();
    QString getToken();
private:
    static GLobalObject *instance;
    QString token;
public slots:
    void loginSuccess(QString login, QString token);
};

#endif // GLOBALOBJECT_H
