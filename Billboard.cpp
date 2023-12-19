#include "Billboard.h"
#include "utilities.h"
//#include "advertisement.h"

Billboard::Billboard(): customers_count_(0), 
                        last_shown_customer_id_(NUMBER_OF_CUSTOMERS),
                        total_payments_(0),
                        time_elapsed_(0) {}

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
    //uint8_t customer_id = getRandomCustomerId();
    uint8_t customer_id;
    while(1) {
        customer_id = getRandomCustomerId();
        if (customer_id != last_shown_customer_id_) {
            last_shown_customer_id_ = customer_id;
            break;
        }
    }
    uint16_t time_increment = customers_[customer_id].printRandomAd(time_elapsed_);
    time_elapsed_ += time_increment;
}