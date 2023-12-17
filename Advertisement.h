#ifndef __ADVERTISEMENT_H
#define __ADVERTISEMENT_H
#define TEXTLIMIT 64
#include "Billboard.h"
//#include "lcd.h"
// #include <stdint.h>

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
    char text[TEXTLIMIT];
    TextType type_;
    TextFrequency frequency_;
    
    public:
    Advertisement(char advertisement[] = "", 
                  TextType text_type = TextType::REGULAR, 
                  TextFrequency text_frequency = TextFrequency::RANDOM);
    char* my_test();
    void print(Billboard &board);
    //void print_ad(); 
};



#endif // __DHT_H