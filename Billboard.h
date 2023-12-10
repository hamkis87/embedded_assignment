#ifndef __BILLBOARD_H
#define __BILLBOARD_H
#include "lcd.h"
// #include <stdint.h>

class Billboard {
    private:
    HD44780 lcd;
    
    public:
    Billboard();
    void print_ad(); 
};



#endif // __DHT_H