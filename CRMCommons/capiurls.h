#ifndef CAPIURLS_H
#define CAPIURLS_H

#endif // CAPIURLS_H

#define AUTHENTICATE_URL "/api/authenticate"
#define MENUS_URL "/api/menus"
#define CUSTOMERS_URL "/api/customers"

enum CRequestType {
    AUTHENTICATION  = 0001,
    MENUS           = 0002,
    CUSTOMERS       = 0003
};
