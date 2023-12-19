#include <string.h>
#include "Advertisement.h"

Advertisement::Advertisement(HD44780 *lcd, char advertisement[], 
                             TextType text_type, 
                             TextFrequency text_frequency): lcd_(lcd) {
    strcpy(text_, advertisement);
    type_ = text_type;
    text_frequency = frequency_;
}

bool Advertisement::printAllowedNow(uint32_t time_elapsed) {
    switch (frequency_) {
        case TextFrequency::EVEN_HOUR:
            return ((time_elapsed/HOUR_TO_MILLISEC)%2 == 0);
        case TextFrequency::ODD_HOUR:
            return ((time_elapsed/HOUR_TO_MILLISEC)%2 == 1);
        case TextFrequency::EVEN_MINUTE:
            return ((time_elapsed/MINUTE_TO_MILLISEC)%2 == 0);
        case TextFrequency::ODD_MINUTE:
            return ((time_elapsed/MINUTE_TO_MILLISEC)%2 == 1);
        default:
            return true;
    }
}

uint16_t Advertisement::printAndDelay(char text[]) {
    lcd_->GoTo(0,0);
    lcd_->WriteText(text);
    switch (type_) {
        case TextType::BLINKING:
            _delay_ms(MILLIS_SHORT);
            return MILLIS_SHORT;
        case TextType::SCROLLING:
            _delay_ms(MILLIS_TINY);
            return MILLIS_TINY;
        default:
            _delay_ms(MILLIS_LONG);
            return MILLIS_LONG;
    }
}

void Advertisement::leftPadWithSpaces(char text[]) {
    for (uint8_t i = 0; i < LCD_SIZE - 1; ++i) {
        text[i] = ' ';
    }
    text[LCD_SIZE - 1] = '\0';
}

uint16_t Advertisement::printBlinking() {
    // blinking ad would be printed for MILLIS_SHORT * 4 millisec
    // plus 1000 * 4 blink delay between each print, so the total
    // is (MILLIS_SHORT+1000) * 4
    uint16_t time_increment = 0;  
    for (uint8_t i = 0; i < 4; ++i) {
        time_increment += printAndDelay(text_);
        lcd_->Clear();
        _delay_ms(CLEAR_DELAY);
        time_increment += CLEAR_DELAY;
    }
    return time_increment;  
}

uint16_t Advertisement::printScrolling() {
    // a scrolling ad with an average length(16 chars)
    // would take approximately (32 + 16) * MILLIS_TINY millisec
    uint16_t time_increment = 0; 
    char scrolled_text[LCD_SIZE];
    char left_padded_text[LCD_SIZE];
    leftPadWithSpaces(left_padded_text);
    leftPadWithSpaces(scrolled_text);
    uint8_t i = LCD_SIZE - 2;
    uint8_t j = 0;
    while ((i >= 0) && (text_[j] != '\0')) {
        for(uint8_t k = 0; k < LCD_SIZE - 2; ++k) {
            scrolled_text[k] = scrolled_text[k + 1];
        }
        scrolled_text[LCD_SIZE - 2] = text_[j];
        --i;
        ++j;
        time_increment += printAndDelay(scrolled_text);
        lcd_->Clear();    
    }
    while (text_[j] != '\0') {
        for(uint8_t k = 1; k < LCD_SIZE - 1; ++k) {
            scrolled_text[k - 1] = scrolled_text[k];
        }
        scrolled_text[LCD_SIZE - 2] = text_[j];
        ++j;
        time_increment += printAndDelay(scrolled_text);
        lcd_->Clear();
    }
    while(strcmp(scrolled_text, left_padded_text) != 0) {
        for(uint8_t k = 1; k < LCD_SIZE; ++k) {
            if (scrolled_text[k] == '\0')
                scrolled_text[k - 1] = ' ';
            else
                scrolled_text[k - 1] = scrolled_text[k];
        }
        time_increment += printAndDelay(scrolled_text);
        lcd_->Clear();
    }
    return time_increment;   
}

uint16_t Advertisement::printRegular() {
    uint16_t time_increment = 0; 
    time_increment += printAndDelay(text_);
    lcd_->Clear();
    return time_increment;
}

uint16_t Advertisement::printAd(uint32_t time_elapsed) {
    if (!printAllowedNow(time_elapsed))
        return 0;
    switch (type_) {
        case TextType::BLINKING :
            return printBlinking();
        case TextType::SCROLLING :
            return printScrolling();
        default: // for TextType::REGULAR
            return printRegular();
    }
}