#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "Billboard.h"
#include "Advertisement.h"
#include "Customer.h"
//#include "lcd.h"
//#include "AnalogPin.h"

// https://wokwi.com/projects/365067824797777921

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)
//#define LED_PIN 2
#define NUMBER_OF_CUSTOMERS 4

// void add_customers(Customer customers_list[]) {
//     char name1[] = "Hederlige Harrys Cars";
//     char name2[] = "Farmor Ankas Pajer AB";
//     char name3[] = "Svarte Petters Svartbyggen";
//     char name4[] = "Långbens detektivbyrå";

//     char *names[] = {name1, name2, name3, name4};
//     int amounts[] = {5000, 3000, 1500, 4000};
//     for (int i = 0; i < NUMBER_OF_CUSTOMERS; ++i) {
//         customers_list[i] = Customer(names[i], amounts[i]);
//     }
// }

int main(void){
    Billboard bill_board;   
    Customer customers[NUMBER_OF_CUSTOMERS] = {
        Customer("Hederlige Harrys Cars", 5000),
        Customer("Farmor Ankas Pajer AB", 3000),
        Customer("Svarte Petters Svartbyggen", 1500),
        Customer("Långbens detektivbyrå", 4000)
    };

    // Advertisement advert1("hello hamid!", 
    //                       TextType::REGULAR,
    //                       TextFrequency::RANDOM);
    // advert1.print(bill_board);
    //bill_board.print_ad();
    HD44780 lcd;
    // lcd.Initalize();
    lcd.GoTo(0,0);
    lcd.WriteText(customers[3].name_);

    
    // while(1){
	// 	//uint16_t value = ntc.analogRead(); // 0 - 1023
    //     //int d = (int)(ntc.getTemp() * 100)/100; //5.23 523
    //     //sprintf(text, "%d ", d);
    //     lcd.Clear();
    //     //lcd.GoTo(0,0);
    //     lcd.WriteText(text);
    //     _delay_ms(1000);
    // }
    return 0;
}
