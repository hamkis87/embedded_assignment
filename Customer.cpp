#include <string.h>
#include "Customer.h"
#include "utilities.h"


Customer::Customer(char name[], uint8_t amount_paid) {
    amount_paid_ = amount_paid;
    number_of_ads_ = 0;
    // uint8_t i = 0;
    // while ((i < MAX_NAME_SIZE - 1) && name[i] != '\0') {
    //     name_[i] = name[i];
    //     ++i;
    // }
    // name_[i] = '\0';
    strcpy(name_, name);
}

// Customer::Customer(const Customer &other) {
//     amount_paid_ = other.amount_paid_;
//     strcpy(name_, other.name_);
// }

// Customer& Customer::operator=(const Customer& other) {
//     if (this != &other) {
//         amount_paid_ = other.amount_paid_;
//         strcpy(name_, other.name_);
//     }
//     return *this;
// }

uint8_t Customer::getAmount() const {
    return amount_paid_;
}

void Customer::addAdvertisement(const Advertisement &ad) {
    if (number_of_ads_ < MAX_ADS_NUMBER) {
        ads_[number_of_ads_] = ad;
        ++number_of_ads_;
    }
}

void Customer::printRandomAd(HD44780 &lcd) {
    uint8_t ad_id = (uint8_t)randomUint16InRange(number_of_ads_);
    lcd.GoTo(0,0);
    lcd.WriteText(ads_[ad_id].text_);
    _delay_ms(1000);
    lcd.Clear();
}