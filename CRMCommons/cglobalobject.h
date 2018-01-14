#ifndef GLOBALOBJECT_H
#define GLOBALOBJECT_H

#include <QObject>
#include <QDebug>

namespace CRMCommons {
/**
 * @brief The GLobalObject class
 * The global object singleton, that contains any application
 * variables. This class loaded when application was started
 * and here. With thi class you can access this variables from
 * any other application class.
 */
class GLobalObject : public QObject
{
    Q_OBJECT
public:
    static GLobalObject *getInstance();
    /**
     * @brief getToken get JHipster authentication token
     * @return token
     */
    QString getToken();
private:
    /**
     * @brief JHipster authentication token
     */
    QString token;
public slots:
    /**
     * @brief loginSuccess event emit when user login into application.
     * @param login the user login
     * @param token and the JHipster authentication token
     */
    void loginSuccess(QString login, QString token);
};
}
#endif // GLOBALOBJECT_H
