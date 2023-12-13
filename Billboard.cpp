#include "Billboard.h"
#include "advertisement.h"

Billboard::Billboard() {
    lcd.GoTo(0,0);
}

void Billboard::print_ad() {
    //char advertisement[] = "Hi there! Test advertisement here";
    Advertisement advert1("hello hamid!", 
                          TextType::REGULAR,
                          TextFrequency::RANDOM);
    lcd.WriteText(advert1.my_test());
}