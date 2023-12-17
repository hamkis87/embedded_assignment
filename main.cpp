#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "Billboard.h"
#include "Advertisement.h"
#include "Customer.h"
#include "utilities.h"
//#include "lcd.h"
//#include "AnalogPin.h"

// https://wokwi.com/projects/365067824797777921

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)
//#define LED_PIN 2
#define NUMBER_OF_CUSTOMERS 4

volatile uint32_t millis_count = 0;

void get_all_payments_and_total(Customer customers[], 
                                uint8_t payments[], uint16_t &total) {
    for (uint8_t i = 0; i < NUMBER_OF_CUSTOMERS; ++i) {
        payments[i] = customers[i].getAmount();
        total += payments[i];
    }
}

uint8_t get_random_customer_id(const uint8_t payments[], 
                               const uint16_t &total) {
    uint16_t x = randomUint8InRange(total);
    uint16_t limit = 0;
    uint8_t i = 0;
    while (i < NUMBER_OF_CUSTOMERS) {
        limit += payments[i];
        if (x < limit)
            return i;
        ++i;
    }
    return i - 1; // if x is greater than or equal total 
}

int main(void){
    Billboard bill_board;   
    Customer customers[NUMBER_OF_CUSTOMERS] = {
        Customer("Hederlige Harrys Cars", 50),
        Customer("Farmor Ankas Pajer AB", 30),
        Customer("Svarte Petters Svartbyggen", 15),
        Customer("Långbens detektivbyrå", 40)
    };

    uint16_t total = 0;
    uint8_t payments[NUMBER_OF_CUSTOMERS];
    get_all_payments_and_total(customers, payments, total);
    //uint8_t customer_id = get_random_customer_id(payments, total);

    // Advertisement advert1("hello hamid!", 
    //                       TextType::REGULAR,
    //                       TextFrequency::RANDOM);
    // advert1.print(bill_board);
    //bill_board.print_ad();
    //uint8_t x = randomUint8InRange(NUMBER_OF_CUSTOMERS);
    HD44780 lcd;
    // lcd.Initalize();
    

    // lcd.WriteText("Hi Hamid ");
    while(1){
        lcd.GoTo(0,0);
        uint8_t customer_id = get_random_customer_id(payments, total);
        lcd.WriteText(customers[customer_id].name_);
        //sprintf("hello", "%d ", customers[customer_id].getAmount());
        _delay_ms(1000);
        lcd.Clear();
	// 	//uint16_t value = ntc.analogRead(); // 0 - 1023
    //     //int d = (int)(ntc.getTemp() * 100)/100; //5.23 523
    //     //sprintf(text, "%d ", d);
    //     lcd.Clear();
    //     //lcd.GoTo(0,0);
    //     lcd.WriteText(text);
    //     _delay_ms(1000);
    }
    return 0;
}
