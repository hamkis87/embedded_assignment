#ifndef __ADVERTISEMENT_H
#define __ADVERTISEMENT_H
#define TEXTLIMIT 40
//#include "Billboard.h"
#include <util/delay.h>
#include <stdint.h>
#include "lcd.h"

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
    void printBlinking();
    void printScrolling();
    void printRegular();

    public:
    Advertisement(HD44780 *lcd = nullptr, char advertisement[] = "", 
                  TextType text_type = TextType::REGULAR, 
                  TextFrequency text_frequency = TextFrequency::RANDOM);
    //char text_[TEXTLIMIT];
    // void printAd(HD44780 &lcd);
    void printAd();
    //char* my_test();
    //void print(Billboard &board);
    //void print_ad(); 
};



#endif // __DHT_H