#include <string.h>
#include "Advertisement.h"

Advertisement::Advertisement(HD44780 *lcd, char advertisement[], 
                             TextType text_type, 
                             TextFrequency text_frequency): lcd_(lcd) {
    strcpy(text_, advertisement);
    type_ = text_type;
    text_frequency = frequency_;
}

void Advertisement::printAndDelay(char text[]) {
    lcd_->GoTo(0,0);
    lcd_->WriteText(text);
    switch (type_) {
        case TextType::BLINKING:
            _delay_ms(MILLIS_SHORT);
            break;
        case TextType::SCROLLING:
            _delay_ms(MILLIS_TINY);
            break;
        default:
            _delay_ms(MILLIS_LONG);
    }
}

void Advertisement::leftPadWithSpaces(char text[]) {
    for (uint8_t i = 0; i < LCD_SIZE - 1; ++i) {
        text[i] = ' ';
    }
    text[LCD_SIZE - 1] = '\0';
}

void Advertisement::printBlinking() {
    // blinking ad would be printed for MILLIS_SHORT * 4 millisec
    // plus 1000 * 4 blink delay between each print, so the total
    // is (MILLIS_SHORT+1000) * 4  
    for (uint8_t i = 0; i < 4; ++i) {
        printAndDelay(text_);
        lcd_->Clear();
        _delay_ms(1000);
    }   
}

void Advertisement::printScrolling() {
    // a scrolling ad with an average length(16 chars)
    // would take approximately (32 + 16) * MILLIS_TINY millisec
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
        printAndDelay(scrolled_text);
        lcd_->Clear();    
    }
    while (text_[j] != '\0') {
        for(uint8_t k = 1; k < LCD_SIZE - 1; ++k) {
            scrolled_text[k - 1] = scrolled_text[k];
        }
        scrolled_text[LCD_SIZE - 2] = text_[j];
        ++j;
        printAndDelay(scrolled_text);
        lcd_->Clear();
    }
    while(strcmp(scrolled_text, left_padded_text) != 0) {
        for(uint8_t k = 1; k < LCD_SIZE; ++k) {
            if (scrolled_text[k] == '\0')
                scrolled_text[k - 1] = ' ';
            else
                scrolled_text[k - 1] = scrolled_text[k];
        }
        printAndDelay(scrolled_text);
        lcd_->Clear();
    }   
}

void Advertisement::printRegular() {
    printAndDelay(text_);
    lcd_->Clear();   
}

void Advertisement::printAd() {
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
}