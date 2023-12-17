#include "Billboard.h"
#include "utilities.h"
//#include "advertisement.h"

Billboard::Billboard() {
    lcd_.GoTo(0,0);
    customers_count_ = 0;
    total_payments_ = 0;
}

void Billboard::addCustomer(const Customer& customer) {
    if (customers_count_ < NUMBER_OF_CUSTOMERS) {
        customers_[customers_count_] = customer;
        ++customers_count_;
        total_payments_ += customer.getAmount();
    }
}

uint8_t Billboard::getRandomCustomerId() {
    uint16_t x = randomUint16InRange(total_payments_);
    uint16_t limit = 0;
    uint8_t i = 0;
    while (i < NUMBER_OF_CUSTOMERS) {
        limit += customers_[i].getAmount();
        if (x < limit)
            return i;
        ++i;
    }
    return i - 1; // if x is greater than or equal total 
} 

void Billboard::printAdvertisement() {
    uint8_t customer_id = getRandomCustomerId();
    customers_[customer_id].printRandomAd(lcd_);
    // lcd_.GoTo(0,0);
    //lcd_.WriteText(customers_[customer_id].name_);
    // _delay_ms(1000);
    // lcd_.Clear();
}

// void Billboard::print_ad() {
//     //char advertisement[] = "Hi there! Test advertisement here";
//     Advertisement advert1("hello hamid!", 
//                           TextType::REGULAR,
//                           TextFrequency::RANDOM);
//     lcd.WriteText(advert1.my_test());
// }