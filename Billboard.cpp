#include "Billboard.h"

Billboard::Billboard() {
    lcd.Initalize();
    lcd.GoTo(0,0);
}

void Billboard::print_ad() {
    char advertisement[] = "Test advertisement ";
    lcd.WriteText(advertisement);
}