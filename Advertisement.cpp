#include "Advertisement.h"

Advertisement::Advertisement(char advertisement[], 
                             TextType text_type, 
                             TextFrequency text_frequency) {
    int i = 0;
    while ((i < TEXTLIMIT) && (advertisement[i] != '\0')) {
        text[i] = advertisement[i];
        ++i;
    }
    text[i] = '\0';
    type_ = text_type;
    text_frequency = frequency_;
}

char* Advertisement::my_test() {
    char my_text[15] = "I changed it!";
    static char arr2[20];
    int i = 0;
    while (my_text[i] != '\0') {
        arr2[i] = my_text[i];
        ++i;
    }
    arr2[i] = '\0';
    return arr2; 
}

void Advertisement::print(Billboard &board) {
    char ads[] = "Hi there! Test advertisement here";
    board.lcd.WriteText(ads);
}