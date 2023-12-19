#ifndef __ADVERTISEMENT_H
#define __ADVERTISEMENT_H

#include <util/delay.h>
#include <stdint.h>
#include <string.h>
#include "lcd.h"

#define TEXTLIMIT 40
#define LCD_SIZE 33
#define CLEAR_DELAY 1000
#define MILLIS_TINY 400
#define MILLIS_SHORT 4000
#define MILLIS_LONG 20000
#define MINUTE_TO_MILLISEC 60 // change to 60000
#define HOUR_TO_MILLISEC 360 // change to 3600000

enum class TextType : uint8_t { 
    REGULAR,
    BLINKING,
    SCROLLING
};

enum class TextFrequency : uint8_t { 
    RANDOM, 
    EVEN_HOUR, 
    ODD_HOUR, 
    EVEN_MINUTE, 
    ODD_MINUTE
};

class Advertisement {
    private:
    char text_[TEXTLIMIT];
    TextType type_;
    TextFrequency frequency_;
    HD44780 *lcd_;
    bool printAllowedNow(uint32_t time_elapsed);
    uint16_t printAndDelay(char text[]);
    void leftPadWithSpaces(char text[]);
    uint16_t printBlinking();
    uint16_t printScrolling();
    uint16_t printRegular();

    public:
    Advertisement(HD44780 *lcd = nullptr, char advertisement[] = "", 
                  TextType text_type = TextType::REGULAR, 
                  TextFrequency text_frequency = TextFrequency::RANDOM);
    uint16_t printAd(uint32_t time_elapsed);
};



#endif // __DHT_H