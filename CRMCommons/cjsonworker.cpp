#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include "cjsonworker.h"

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

    QString loginUrl = API_URL;

    loginUrl.append(AUTHENTICATE_URL);

    QUrl loginQUrl(loginUrl);
    QNetworkRequest request(loginQUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject jsonObject;
    jsonObject.insert("username", login);
    jsonObject.insert("password", password);

    networkManager->post(request, QJsonDocument(jsonObject).toJson());
}

void CJsonWorker::getAllMenus()
{
    globalObject = GLobalObject::getInstance();

    QNetworkAccessManager *networkManager = new QNetworkAccessManager();
    connect(networkManager, &QNetworkAccessManager::finished, this, &CJsonWorker::onMenuDataLoaded);

    QString menuUrl = API_URL;
    menuUrl.append(MENUS_URL);

    QUrl menuQUrl(menuUrl);
    QNetworkRequest request(menuQUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(AUTHORIZATION_HEADER, getTokenBearer().toLocal8Bit());
    networkManager->get(request);
}

QString CJsonWorker::getTokenBearer()
{
    QString token(BEARER_PART);
    token.append(globalObject->getToken());
    return token;
}

void CJsonWorker::onAuthenticateDataLoaded(QNetworkReply *reply)
{
    qDebug() << "Server sent back the data.";
    emit onAuthenticateFinished(reply);
}

void CJsonWorker::onMenuDataLoaded(QNetworkReply *reply)
{
    qDebug() << "Menu was loaded from server...";
    emit onMenuLoadFinished(reply);
}
