#include <string.h>
#include "Advertisement.h"

Advertisement::Advertisement(HD44780 *lcd, char advertisement[], 
                             TextType text_type, 
                             TextFrequency text_frequency): lcd_(lcd) {
    strcpy(text_, advertisement);
    type_ = text_type;
    text_frequency = frequency_;
}

void Advertisement::printAd() {
    lcd_->GoTo(0,0);
    lcd_->WriteText(text_);
    _delay_ms(1000);
    lcd_->Clear();
}

// void Advertisement::printAd(HD44780 &lcd) {
//     lcd.GoTo(0,0);
//     lcd.WriteText(text_);
//     _delay_ms(1000);
//     lcd.Clear();
// }