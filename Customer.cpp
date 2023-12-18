#include <string.h>
#include "Customer.h"
#include "utilities.h"


// Customer::Customer(char name[], uint8_t amount_paid) {
//     amount_paid_ = amount_paid;
//     number_of_ads_ = 0;
//     strcpy(name_, name);
// }
Customer::Customer(HD44780 *lcd, uint8_t amount_paid): lcd_(lcd), amount_paid_(amount_paid), number_of_ads_(0) {
}

uint8_t Customer::getAmount() const {
    return amount_paid_;
}

void Customer::addAdvertisement(const Advertisement &ad) {
    if (number_of_ads_ < MAX_ADS_NUMBER) {
        ads_[number_of_ads_] = ad;
        ++number_of_ads_;
    }
}

void Customer::printRandomAd() {
    uint8_t ad_id = (uint8_t)randomUint16InRange(number_of_ads_);
    ads_[ad_id].printAd();
}
// void Customer::printRandomAd(HD44780 &lcd) {
//     uint8_t ad_id = (uint8_t)randomUint16InRange(number_of_ads_);
//     ads_[ad_id].printAd(lcd);
// }