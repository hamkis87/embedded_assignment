#ifndef __CUSTOMER_H
#define __CUSTOMER_H
#include "Advertisement.h"

#define MAX_NAME_SIZE 4
#define MAX_ADS_NUMBER 3

class Customer {
    private:
    // char name_[MAX_NAME_SIZE];
    Advertisement ads_[MAX_ADS_NUMBER];
    // amount_paid_ is the actual amount divided by 100
    uint8_t amount_paid_; 
    uint8_t number_of_ads_;
    
    public:
    // name_ made public for test only
    //char name_[MAX_NAME_SIZE];
    //Customer(char name[] = "", uint8_t amount_paid = 0);
    Customer(uint8_t amount_paid = 0);
    uint8_t getAmount() const;
    void addAdvertisement(const Advertisement &ad);
    uint16_t printRandomAd(uint32_t time_elapsed);
};


#endif // __DHT_H