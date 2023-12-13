#ifndef __ADVERTISEMENT_H
#define __ADVERTISEMENT_H
#define TEXTLIMIT 64
//#include "lcd.h"
// #include <stdint.h>

enum class TextType { 
    REGULAR,
    BLINKING,
    SCROLLING
};

enum class TextFrequency { 
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
    Advertisement(char advertisement[], 
                  TextType text_type, 
                  TextFrequency text_frequency);
    char* my_test();
    //void print_ad(); 
};



#endif // __DHT_H