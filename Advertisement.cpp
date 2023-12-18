#include <string.h>
#include "Advertisement.h"

Advertisement::Advertisement(HD44780 *lcd, char advertisement[], 
                             TextType text_type, 
                             TextFrequency text_frequency): lcd_(lcd) {
    strcpy(text_, advertisement);
    type_ = text_type;
    text_frequency = frequency_;
}

void Advertisement::printBlinking() {
    lcd_->WriteText(text_);
    _delay_ms(800);
    lcd_->Clear();
    _delay_ms(400);
    lcd_->WriteText(text_);
    _delay_ms(800);
    lcd_->Clear();   
}

void Advertisement::printScrolling() {
    lcd_->WriteText(text_);
    _delay_ms(2000);
    lcd_->Clear();   
}

void Advertisement::printRegular() {
    lcd_->WriteText(text_);
    _delay_ms(2000);
    lcd_->Clear();   
}

void Advertisement::printAd() {
    lcd_->GoTo(0,0);
    switch (type_) {
        case TextType::BLINKING :
            printBlinking();
            break;
        case TextType::SCROLLING :
            printScrolling();
            break;
        default: // for TextType::REGULAR
            printRegular();
    }
    // lcd_->WriteText(text_);
    // _delay_ms(1000);
    // lcd_->Clear();
}