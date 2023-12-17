#include "Customer.h"

Customer::Customer(char name[], uint8_t amount_paid) {
    amount_paid_ = amount_paid;
    uint8_t i = 0;
    while ((i < MAX_NAME_SIZE - 1) && name[i] != '\0') {
        name_[i] = name[i];
        ++i;
    }
    name_[i] = '\0';
}

Customer::Customer(const Customer &other) {
    amount_paid_ = other.amount_paid_;
    uint8_t i = 0;
    while (i < MAX_NAME_SIZE - 1 && other.name_[i] != '\0') {
        name_[i] = other.name_[i];
        ++i;
    }
    name_[i] = '\0';
}

Customer& Customer::operator=(const Customer& other) {
    if (this != &other) {
        amount_paid_ = other.amount_paid_;
        uint8_t i = 0;
        while (i < MAX_NAME_SIZE - 1 && other.name_[i] != '\0') {
            name_[i] = other.name_[i];
            ++i;
        }
        name_[i] = '\0';
    }
    return *this;
}

uint8_t Customer::getAmount() {
    return amount_paid_;
}


// Customer::add_advertisement(Advertisement ad) {

// }
