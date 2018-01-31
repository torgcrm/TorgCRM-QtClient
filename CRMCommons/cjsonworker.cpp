#include "cjsonworker.h"

using namespace CRMCommons;

static CJsonWorker *_cJsonWorker = NULL;

CJsonWorker::CJsonWorker()
{
    networkAccessManager = new QNetworkAccessManager();
    connect(networkAccessManager, SIGNAL(finished(QNetworkReply *)),
            this, SLOT(onDataLoaded(QNetworkReply *)));
}

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

    QString loginUrl = API_URL;
    loginUrl.append(AUTHENTICATE_URL);

    QUrl loginQUrl(loginUrl);
    QNetworkRequest request(loginQUrl);
    request.setAttribute(QNetworkRequest::User, CRequestType::AUTHENTICATION);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject jsonObject;
    jsonObject.insert("username", login);
    jsonObject.insert("password", password);

    networkAccessManager->post(request, QJsonDocument(jsonObject).toJson());
}

void CJsonWorker::getAllMenus()
{
    QString menuUrl = API_URL;
    menuUrl.append(MENUS_URL);
    QUrl menuQUrl(menuUrl);

    QNetworkRequest request(menuQUrl);
    request.setAttribute(QNetworkRequest::User, CRequestType::MENUS);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(AUTHORIZATION_HEADER, getTokenBearer().toLocal8Bit());

    networkAccessManager->get(request);
}

void CJsonWorker::getAllCustomers()
{
    QString localUrl = API_URL;
    localUrl.append(CUSTOMERS_URL);
    QUrl localQUrl(localUrl);

    QNetworkRequest request(localQUrl);
    request.setAttribute(QNetworkRequest::User, CRequestType::CUSTOMERS);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(AUTHORIZATION_HEADER, getTokenBearer().toLocal8Bit());

    networkAccessManager->get(request);
}

void CJsonWorker::saveCustomer(CRMModels::Customer *customer)
{
    QString localUrl = API_URL;
    localUrl.append(SAVE_CUSTOMER_URL);
    QUrl localQUrl(localUrl);

    QNetworkRequest request(localQUrl);
    request.setAttribute(QNetworkRequest::User, CRequestType::SAVE_CUSTOMER);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(AUTHORIZATION_HEADER, getTokenBearer().toLocal8Bit());

    QJsonObject jsonObject;
    jsonObject.insert(JSON_CSTMR_FULLNAME, customer->getFullName());
    jsonObject.insert(JSON_CSTMR_COMMENT, customer->getComment());
    jsonObject.insert(JSON_CSTMR_EMAIL, customer->getEmail());
    jsonObject.insert(JSON_CSTMR_FAX, customer->getFax());
//    jsonObject.insert(JSON_CSTMR_ID, customer->getId());
    jsonObject.insert(JSON_CSTMR_PHONE, customer->getPhone());
    jsonObject.insert(JSON_CSTMR_SOURCE, customer->getSource());
//    jsonObject.insert(JSON_CSTMR_TYPEID, customer->getTypeId());

    qDebug() << "Post Customer JSON object to the server.";
    networkAccessManager->post(request, QJsonDocument(jsonObject).toJson());
}

void CJsonWorker::updateCustomer(CRMModels::Customer *customer, int customerId)
{
    QString localUrl = API_URL;
    localUrl.append(SAVE_CUSTOMER_URL);
    QUrl localQUrl(localUrl);

    QNetworkRequest request(localQUrl);
    request.setAttribute(QNetworkRequest::User, CRequestType::SAVE_CUSTOMER);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(AUTHORIZATION_HEADER, getTokenBearer().toLocal8Bit());

    QJsonObject jsonObject;
    jsonObject.insert(JSON_CSTMR_FULLNAME, customer->getFullName());
    jsonObject.insert(JSON_CSTMR_COMMENT, customer->getComment());
    jsonObject.insert(JSON_CSTMR_EMAIL, customer->getEmail());
    jsonObject.insert(JSON_CSTMR_FAX, customer->getFax());
    jsonObject.insert(JSON_CSTMR_ID, customer->getId());
    jsonObject.insert(JSON_CSTMR_PHONE, customer->getPhone());
    jsonObject.insert(JSON_CSTMR_SOURCE, customer->getSource());
//    jsonObject.insert(JSON_CSTMR_TYPEID, customer->getTypeId());

    qDebug() << "Post Customer JSON object to the server.";
    networkAccessManager->put(request, QJsonDocument(jsonObject).toJson());
}

void CJsonWorker::deleteCustomer(int customerId)
{
    QString localUrl = API_URL;
    localUrl.append(DELETE_CUSTOMER_URL);
    localUrl.append(QString::number(customerId));

    QUrl localQUrl(localUrl);

    QNetworkRequest request(localQUrl);
    request.setAttribute(QNetworkRequest::User, CRequestType::DELETE_CSTMR);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(AUTHORIZATION_HEADER, getTokenBearer().toLocal8Bit());

    qDebug() << "Delete Customer by customer id.";
    networkAccessManager->deleteResource(request);
}

void CJsonWorker::getAllTasks()
{
    qDebug() << "Trying to load tasks from server...";
    QString localUrl = API_URL;
    localUrl.append(TASKS_URL);
    QUrl localQUrl(localUrl);

    QNetworkRequest request(localQUrl);
    request.setAttribute(QNetworkRequest::User, CRequestType::TASKS);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(AUTHORIZATION_HEADER, getTokenBearer().toLocal8Bit());

    networkAccessManager->get(request);
}

void CJsonWorker::saveTask(CRMModels::Task *task)
{
    qDebug() << "Trying to save task...";
    QString localUrl = API_URL;
    localUrl.append(SAVE_TASK_URL);
    QUrl localQUrl(localUrl);

    QNetworkRequest request(localQUrl);
    request.setAttribute(QNetworkRequest::User, CRequestType::SAVE_CUSTOMER);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(AUTHORIZATION_HEADER, getTokenBearer().toLocal8Bit());

    QJsonObject jsonObject;
//    jsonObject.insert(JSON_TASK_ID, task->getId());
//    jsonObject.insert(JSON_TASK_BEGINDATE, task->getBeginDate().toString());
//    jsonObject.insert(JSON_TASK_ENDDATE, task->getEndDate().toString());
    jsonObject.insert(JSON_TASK_COMMENT, task->getComment());
//    jsonObject.insert(JSON_TASK_TYPE, task->getType());
//    jsonObject.insert(JSON_TASK_MANAGER, task->getManagerId());
    jsonObject.insert(JSON_TASK_TITLE, task->getTitle());

    qDebug() << "Post Customer JSON object to the server.";
    networkAccessManager->post(request, QJsonDocument(jsonObject).toJson());
}

QString CJsonWorker::getTokenBearer()
{
    QString token(BEARER_PART);
    token.append(globalObject->getToken());
    return token;
}

void CJsonWorker::onDataLoaded(QNetworkReply *reply) {
    CRequestType requestType = static_cast<CRequestType>
            (reply->request().attribute(QNetworkRequest::User).toInt());

    switch (requestType)
    {
        case CRequestType::AUTHENTICATION:
            onAuthenticateDataLoaded(reply);
            break;
        case CRequestType::MENUS:
            onMenuDataLoaded(reply);
            break;
        case CRequestType::CUSTOMERS:
            onCustomersDataLoaded(reply);
            break;
        case CRequestType::TASKS:
            onTasksDataLoaded(reply);
            break;
        case CRequestType::DELETE_CSTMR:
            onCustomerDeleted(reply);
            break;
        case CRequestType::SAVE_CUSTOMER:
            onCustomerSaved(reply);
            break;
        default:
            break;
    }
    reply->deleteLater();
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

void CJsonWorker::onCustomersDataLoaded(QNetworkReply *reply)
{
    qDebug() << "Customers was loaded from server...";
    emit onCustomersLoadFinished(reply);
}

void CJsonWorker::onTasksDataLoaded(QNetworkReply *reply)
{
    qDebug() << "Tasks was loaded from server...";
    emit onTasksLoadFinished(reply);
}

void CJsonWorker::onCustomerDeleted(QNetworkReply *reply)
{
    qDebug() << "Customer was deleted";
    emit onCustomerDeletedSignal(reply);
}

void CJsonWorker::onCustomerSaved(QNetworkReply *reply)
{
    qDebug() << "Customer was saved";
    CRMModels::Customer *customer = new CRMModels::Customer();
    customer->fromJSON(reply->readAll());

    emit onCustomerSavedSignal(customer);
}
