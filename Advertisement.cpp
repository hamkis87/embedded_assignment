#include <string.h>
#include "Advertisement.h"

Advertisement::Advertisement(HD44780 *lcd, char advertisement[], 
                             TextType text_type, 
                             TextFrequency text_frequency): lcd_(lcd) {
    strcpy(text_, advertisement);
    type_ = text_type;
    text_frequency = frequency_;
}

void Advertisement::leftPadWithSpaces(char arr[]) {
    for (uint8_t i = 0; i < LCD_SIZE - 1; ++i) {
        arr[i] = ' ';
    }
    arr[LCD_SIZE - 1] = '\0';
}

void Advertisement::printBlinking() {
    lcd_->GoTo(0,0);
    lcd_->WriteText(text_);
    _delay_ms(800);
    lcd_->Clear();
    lcd_->GoTo(0,0);
    _delay_ms(400);
    lcd_->WriteText(text_);
    _delay_ms(800);
    lcd_->Clear();   
}

void Advertisement::printScrolling() {
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
        lcd_->GoTo(0,0);
        lcd_->WriteText(scrolled_text);
        _delay_ms(400);
        lcd_->Clear();    
    }
    while (text_[j] != '\0') {
        for(uint8_t k = 1; k < LCD_SIZE - 1; ++k) {
            scrolled_text[k - 1] = scrolled_text[k];
        }
        scrolled_text[LCD_SIZE - 2] = text_[j];
        ++j;
        lcd_->GoTo(0,0);
        lcd_->WriteText(scrolled_text);
        _delay_ms(400);
        lcd_->Clear();
    }
    while(strcmp(scrolled_text, left_padded_text) != 0) {
        for(uint8_t k = 1; k < LCD_SIZE; ++k) {
            if (scrolled_text[k] == '\0')
                scrolled_text[k - 1] = ' ';
            else
                scrolled_text[k - 1] = scrolled_text[k];
        }
        lcd_->GoTo(0,0);
        lcd_->WriteText(scrolled_text);
        _delay_ms(400);
        lcd_->Clear();
    }   
}

void Advertisement::printRegular() {
    lcd_->GoTo(0,0);
    lcd_->WriteText(text_);
    _delay_ms(2000);
    lcd_->Clear();   
}

void Advertisement::printAd() {
    //lcd_->GoTo(0,0);
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