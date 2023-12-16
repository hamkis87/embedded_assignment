#ifndef __CUSTOMER_H
#define __CUSTOMER_H
#include "Advertisement.h"

#define MAX_NAME_SIZE 32
#define MAX_ADS_NUMBER 4

class Customer {
    private:
    // char name_[MAX_NAME_SIZE];
    Advertisement ads_[MAX_ADS_NUMBER];
    uint16_t amount_paid_;
    uint8_t number_of_ads_;
    
    public:
    // name_ made public for test only
    char name_[MAX_NAME_SIZE];
    Customer(char name[], uint16_t amount_paid);
    Customer(const Customer &other);
    Customer& operator=(const Customer& other);
    // void add_advertisement(Advertisement ad);
    //void print_ad();
};


#endif // __DHT_H