#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "Billboard.h"
#include "Advertisement.h"
#include "Customer.h"
//#include "utilities.h"
//#include "lcd.h"
//#include "AnalogPin.h"
// https://wokwi.com/projects/365067824797777921

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)
//#define LED_PIN 2
//#define NUMBER_OF_CUSTOMERS 4

//volatile uint32_t millis_count = 0;

int main(void){
    Billboard bill_board;
    Customer c1("Hed", 50);
    Customer c2("Far", 30);
    Customer c3("Sva", 15);
    Customer c4("Lån", 40);

    c1.addAdvertisement(Advertisement("Köp bil hos Harry",
                                      TextType::REGULAR,
                                      TextFrequency::RANDOM));
    
    c2.addAdvertisement(Advertisement("Köp paj hos Farmor Anka",
                                      TextType::BLINKING,
                                      TextFrequency::RANDOM));
    
    c3.addAdvertisement(Advertisement("Låt Petter bygga åt dig",
                                      TextType::REGULAR,
                                      TextFrequency::EVEN_MINUTE));
    
    c4.addAdvertisement(Advertisement("Mysterier? Ring Långben",
                                      TextType::REGULAR,
                                      TextFrequency::EVEN_HOUR));

    bill_board.addCustomer(c1);
    bill_board.addCustomer(c2);
    bill_board.addCustomer(c3);
    bill_board.addCustomer(c4);

    // Advertisement advert1("hello hamid!", 
    //                       TextType::REGULAR,
    //                       TextFrequency::RANDOM);
    // advert1.print(bill_board);
    //bill_board.print_ad();
    //uint8_t x = randomUint8InRange(NUMBER_OF_CUSTOMERS);
    //HD44780 lcd;
    // lcd.Initalize();
    

    // lcd.WriteText("Hi Hamid ");
    while(1){
        bill_board.printAdvertisement(); 
    //     uint8_t customer_id = get_random_customer_id(payments, total);
    //     //lcd.WriteText(customers[customer_id].name_);
    //     customers[customer_id].print_ad();
    //     //sprintf("hello", "%d ", customers[customer_id].getAmount());
    //     _delay_ms(1000);
    //     lcd.Clear();
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
