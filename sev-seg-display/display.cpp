#include "display.h"

#include <Arduino.h>

namespace display {

    void reset() {
        for(int i = 0; i < 8; i++){
            digitalWrite(seg_pins[i], common_cathode);
        }
    }
    
    /**
     * Reads the individual bits of the char
     * and sets the LED segment on or off depending
     * on the value of the bit being read.
     */
    void display_digit(int number) {
        unsigned char num_char = digits[number];
        
        for(int i = 7; i >= 0 ; i--){
            bool bit = (num_char >> (i-1)) & 1;
            unsigned int pin_idx = 7 - i;
            digitalWrite(seg_pins[pin_idx],bit);
        }
    }

    void display_number(int number) {
    }
}
