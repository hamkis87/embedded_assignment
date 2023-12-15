#ifndef __CUSTOMER_H
#define __CUSTOMER_H
#include "Advertisement.h"

#define MAX_NAME_SIZE 32
#define MAX_ADS_NUMBER 8

class Customer {
    private:
    // char name_[MAX_NAME_SIZE];
    Advertisement ads_[MAX_ADS_NUMBER];
    int amount_paid_;
    int number_of_ads_;
    
    public:
    // name_ made public for test only
    char name_[MAX_NAME_SIZE];
    Customer(char name[], int amount_paid);
    // Customer(const Customer &c);
    // void add_advertisement(Advertisement ad);
    //void print_ad();
};


#endif // __DHT_H