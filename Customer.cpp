#include <string.h>
#include "Customer.h"
#include "utilities.h"


Customer::Customer(uint8_t amount_paid): 
amount_paid_(amount_paid), number_of_ads_(0) {}

uint8_t Customer::getAmount() const {
    return amount_paid_;
}

void Customer::addAdvertisement(const Advertisement &ad) {
    if (number_of_ads_ < MAX_ADS_NUMBER) {
        ads_[number_of_ads_] = ad;
        ++number_of_ads_;
    }
}

uint16_t Customer::printRandomAd(uint32_t time_elapsed) {
    uint8_t ad_id = (uint8_t)randomUint16InRange(number_of_ads_);
    return ads_[ad_id].printAd(time_elapsed);
}
