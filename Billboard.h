#ifndef __BILLBOARD_H
#define __BILLBOARD_H

#include "Customer.h"
// #include <stdint.h>

#define NUMBER_OF_CUSTOMERS 4

class Billboard {
    private:
    uint8_t customers_count_;
    uint8_t last_shown_customer_id_;
    uint16_t total_payments_;
    uint32_t time_elapsed_;
    Customer customers_[NUMBER_OF_CUSTOMERS];
    uint8_t getRandomCustomerId();     
    public:
    Billboard();
    void addCustomer(const Customer &customer);
    void printAdvertisement();
};



#endif // __DHT_H