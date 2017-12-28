#include "cjsonworker.h"
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

static CJsonWorker *instance = NULL;

CJsonWorker *CJsonWorker::getInstance()
{
    if (!instance) {
        instance = new CJsonWorker();
    }
    return instance;
}

void CJsonWorker::authenticate(QString login, QString password)
{
    QNetworkAccessManager *networkManager = new QNetworkAccessManager;
    connect(networkManager, &QNetworkAccessManager::finished, this, &CJsonWorker::onAuthenticateDataLoaded);

    QUrl loginUrl("http://localhost:8080/api/authenticate");
    QNetworkRequest request(loginUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject jsonObject;
    jsonObject.insert("username", login);
    jsonObject.insert("password", password);

    networkManager->post(request, QJsonDocument(jsonObject).toJson());
}

void CJsonWorker::onAuthenticateDataLoaded(QNetworkReply *reply)
{
    qDebug() << "onAuthenticateDataLoaded:::";
    qDebug() << reply->readAll();
    emit onAuthenticateFinished(reply);
}
