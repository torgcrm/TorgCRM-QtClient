#ifndef CAPIURLS_H
#define CAPIURLS_H

#endif // CAPIURLS_H

#define AUTHENTICATE_URL "/api/authenticate"
#define MENUS_URL "/api/menus"
#define CUSTOMERS_URL "/api/customers"
#define SAVE_CUSTOMER_URL "/api/customers"
#define TASKS_URL "/api/tasks"
#define SAVE_TASK_URL "/api/tasks"
#define DELETE_CUSTOMER_URL "/api/customers/"

namespace CRMCommons {
enum CRequestType {
    AUTHENTICATION  = 0001,
    MENUS           = 0002,
    CUSTOMERS       = 0003,
    SAVE_CUSTOMER   = 0004,
    TASKS           = 0005,
    DELETE_CSTMR    = 0006,
    CSTMR_BY_ID     = 0007,
    CSTMR_UPDATE    = 0010
};
}
