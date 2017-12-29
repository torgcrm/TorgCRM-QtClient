#include "cjsonworker.h"
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

CJsonWorker *CJsonWorker::getInstance()
{
    if (!_cJsonWorker) {
        _cJsonWorker = new CJsonWorker();
    }
    return _cJsonWorker;
}

void CJsonWorker::authenticate(QString login, QString password)
{
    qDebug() << "Trying to authenticate...";
    QNetworkAccessManager *networkManager = new QNetworkAccessManager();
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
    qDebug() << "Server sent back the data.";
    emit onAuthenticateFinished(reply);
}
