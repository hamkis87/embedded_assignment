#include <avr/io.h>
//#include <util/delay.h>
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

//volatile uint32_t millis_count = 0;

int main(void){
    HD44780 lcd;
    Billboard bill_board;

    Customer c1(50);
    Customer c2(30);
    Customer c3(15);
    Customer c4(40);
    Customer c5(10);
    Customer c6(60);

    c1.addAdvertisement(Advertisement(&lcd, "Köp bil hos Harry",
                                      TextType::REGULAR,
                                      TextFrequency::RANDOM));
    c1.addAdvertisement(Advertisement(&lcd, "En god bilaffär (för Harry!)",
                                      TextType::REGULAR,
                                      TextFrequency::RANDOM));
    c1.addAdvertisement(Advertisement(&lcd, "Hederlige Harrys Bilar",
                                      TextType::BLINKING,
                                      TextFrequency::RANDOM));
    
    c2.addAdvertisement(Advertisement(&lcd, "Köp paj hos Farmor Anka",
                                      TextType::BLINKING,
                                      TextFrequency::RANDOM));
    c2.addAdvertisement(Advertisement(&lcd, "Skynda innan Mårten ätit alla pajer",
                                      TextType::REGULAR,
                                      TextFrequency::RANDOM));
    
    c3.addAdvertisement(Advertisement(&lcd, "Låt Petter bygga åt dig",
                                      TextType::REGULAR,
                                      TextFrequency::EVEN_MINUTE));
    c3.addAdvertisement(Advertisement(&lcd, "Bygga svart? Ring Petter",
                                      TextType::REGULAR,
                                      TextFrequency::ODD_MINUTE));
    
    c4.addAdvertisement(Advertisement(&lcd, "Mysterier? Ring Långben",
                                      TextType::REGULAR,
                                      TextFrequency::EVEN_HOUR));
    c4.addAdvertisement(Advertisement(&lcd, "Långben fixar biffen",
                                      TextType::REGULAR,
                                      TextFrequency::ODD_HOUR));

    c5.addAdvertisement(Advertisement(&lcd, "Synas här? IOT:s Reklambyrå",
                                      TextType::CUSTOMIZED,
                                      TextFrequency::RANDOM));

    c6.addAdvertisement(Advertisement(&lcd, "T-Röd - för dig som tänkt klart",
                                      TextType::REGULAR,
                                      TextFrequency::RANDOM));
    c6.addAdvertisement(Advertisement(&lcd, "Claes Månsson - om flickan själv får välja",
                                      TextType::REGULAR,
                                      TextFrequency::RANDOM));

    bill_board.addCustomer(c1);
    bill_board.addCustomer(c2);
    bill_board.addCustomer(c3);
    bill_board.addCustomer(c4);
    bill_board.addCustomer(c5);
    bill_board.addCustomer(c6);

    while(1){
        bill_board.printAdvertisement();
    }
    return 0;
}
