#include "Customer.h"

Customer::Customer(char name[], int amount_paid) {
    amount_paid_ = amount_paid;
    int i = 0;
    while (name[i] != '\0' && (i < MAX_NAME_SIZE - 1)) {
        name_[i] = name[i];
        ++i;
    }
    name_[i] = '\0';
}

// Customer::Customer(const Customer &c) {
//     amount_paid_ = c.amount_paid_;
//     int i = 0;
//     while (c.name_[i] != '\0' && (i < MAX_NAME_SIZE - 1)) {
//         name_[i] = c.name_[i];
//         ++i;
//     }
//     name_[i] = '\0';

// }

// Customer::add_advertisement(Advertisement ad) {

// }
