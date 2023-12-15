#ifndef __BILLBOARD_H
#define __BILLBOARD_H
#include "lcd.h"
// #include <stdint.h>

class Billboard {
    private:
    HD44780 lcd;
    
    public:
    Billboard();
    friend class Advertisement;
    //void print_ad();
};



#endif // __DHT_H