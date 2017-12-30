#ifndef CJSONWORKER_H
#define CJSONWORKER_H

#include <QObject>
#include <QNetworkReply>
#include "capiurls.h"
#include "cglobalobject.h"

#define AUTHORIZATION_HEADER "Authorization"
#define BEARER_PART "Bearer "

/**
 * @brief The CJsonWorker class helper to work with REST api
 */
class CJsonWorker : public QObject
{
    Q_OBJECT
public:
    static CJsonWorker *getInstance();
    /**
     * @brief authenticate this method send data to /api/authenticate login and password
     * @param login
     * @param password
     */
    void authenticate(QString login, QString password);
    /**
     * @brief getAllMenus return JSON with menu list
     */
    void getAllMenus();
private:
    const QString API_URL = "http://localhost:8080";
    GLobalObject *globalObject = GLobalObject::getInstance();
    QString getTokenBearer();
private slots:
    void onAuthenticateDataLoaded(QNetworkReply *reply);
    void onMenuDataLoaded(QNetworkReply *reply);
signals:
    /**
     * @brief onAuthenticateFinished this signal should rise when the data sent to the
     * server and server sent back the answer.
     * @param reply JSON object from JHipster server.
     */
    void onAuthenticateFinished(QNetworkReply *reply);
    /**
     * @brief onMenuLoadFinished this signal rise when the server return JSON with menu list
     * @param reply network reply
     */
    void onMenuLoadFinished(QNetworkReply *reply);
};

static CJsonWorker *_cJsonWorker = NULL;

#endif // CJSONWORKER_H
