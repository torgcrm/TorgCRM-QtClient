#ifndef CJSONWORKER_H
#define CJSONWORKER_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <capiurls.h>

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
private slots:
    void onAuthenticateDataLoaded(QNetworkReply *reply);
signals:
    /**
     * @brief onAuthenticateFinished this signal should rise when the data sent to the
     * server and server sent back the answer.
     * @param reply JSON object from JHipster server.
     */
    void onAuthenticateFinished(QNetworkReply *reply);
};

#endif // CJSONWORKER_H
