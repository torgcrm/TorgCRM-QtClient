#ifndef CJSONWORKER_H
#define CJSONWORKER_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTreeWidgetItem>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>

#include "capiurls.h"
#include "cglobalobject.h"
#include "customer.h"
#include "task.h"

#define AUTHORIZATION_HEADER "Authorization"
#define BEARER_PART "Bearer "
#define TYPE_ATTRIBUTE = "RequestType"

namespace CRMCommons {
/**
 * @brief The CJsonWorker class helper to work with REST api
 */
class CJsonWorker : public QObject
{
    Q_OBJECT
public:
    CJsonWorker();
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
    /**
     * @brief getAllCustomers return JSON object with customers from JHipster
     */
    void getAllCustomers();
    /**
     * @brief getCustomerById get customer by id
     * @param customerId customer id
     */
    void getCustomerById(QString customerId);
    /**
     * @brief saveCustomer post JSON object with Customer to JHipster server
     * @param customer Customer model
     */
    void saveCustomer(CRMModels::Customer *customer);
    /**
     * @brief deleteCustomer delete customer using rest framework
     * @param customerId customer id
     */
    void updateCustomer(CRMModels::Customer *customer, int customerId);
    /**
     * @brief deleteCustomer delete customer using rest framework
     * @param customerId customer id
     */
    void deleteCustomer(int customerId);
    /**
     * @brief getAllTasks return JSON object with task list from JHipster server
     */
    void getAllTasks();
    /**
     * @brief saveTask post JSON object with Task to JHsipter server
     * @param task Task model
     */
    void saveTask(CRMModels::Task *task);
private:
    const QString API_URL = "http://localhost:8080";
    GLobalObject *globalObject = GLobalObject::getInstance();
    QString getTokenBearer();
    QNetworkAccessManager *networkAccessManager;

    void onAuthenticateDataLoaded(QNetworkReply *reply);
    void onMenuDataLoaded(QNetworkReply *reply);
    void onCustomersDataLoaded(QNetworkReply *reply);
    void onTasksDataLoaded(QNetworkReply *reply);
    void onCustomerDeleted(QNetworkReply *reply);
    void onCustomerSaved(QNetworkReply *reply);
    void onCustomerGetById(QNetworkReply *reply);
private slots:
    /**
     * @brief onDataLoaded slot execute when server return QNetworkReply
     * @param reply response from serverm, in this app it is JSON object.
     */
    void onDataLoaded(QNetworkReply *reply);
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
    /**
     * @brief onCustomersLoadFinished this signal rise when the server return JSON with customer list
     * @param reply network reply with JSON
     */
    void onCustomersLoadFinished(QNetworkReply *reply);
    /**
     * @brief onTasksLoadFinished this signal rise when the server return JSON with task list
     * @param reply network reply with JSON
     */
    void onTasksLoadFinished(QNetworkReply *reply);
    /**
     * @brief onCustomerSavedSignal When new customer was saved this signal will rise
     * @param customer customer object
     */
    void onCustomerSavedSignal(CRMModels::Customer *customer);
    /**
     * @brief onCustomerDeletedSignal emit this signal after customer was deleted
     */
    void onCustomerDeletedSignal(QNetworkReply *reply);
    /**
     * @brief onCustomerGetByIdSignal get customer by id signal
     * @param reply json reply
     */
    void onCustomerGetByIdSignal(CRMModels::Customer *customer);
};
}
#endif // CJSONWORKER_H
