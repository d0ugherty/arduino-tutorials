/**
 * Helper functions for the 7-segment digital  display
 *
 */
#include "display.h"

namespace display {
bool mode = common_cathode;
unsigned long current_ms;

void Reset(){
    digitalWrite(pinA, !mode);
    digitalWrite(pinB, !mode);
    digitalWrite(pinC, !mode);
    digitalWrite(pinD, !mode);
    digitalWrite(pinE, !mode);
    digitalWrite(pinF, !mode);
    digitalWrite(pinG, !mode);
    digitalWrite(pinH, !mode);

    for(byte i = 0; i < chars_count; i++) {
        digitalWrite(seg[i], mode);
    }
}

void print_digit(char digit, int digit_port){
    Reset();
    
    int char_idx = -1;
    // search for character in array
    for(int i = 0; i < chars_count; i++) {
        if(digit == Char[i][8]) {
            char_idx = i;
        }
    }
    // turn off the pin if char is not found
    
    if(char_idx == -1) {
        digitalWrite(pinG, !mode);
    } else {
        // print char if found
        for(int i = 0; i <= 7; i++) {
            if(mode == common_anode) {
                digitalWrite(seg[i], !Char[char_idx][i]);
            } else if(mode == common_cathode) {
                digitalWrite(seg[i], Char[char_idx][i]);
            }
        }
    }
}


void print_display(String str, int delay) {
    unsigned long previous_ms = 0;
    char char1 = str.charAt(0);
    char char2 = str.charAt(1);
    char char3 = str.charAt(2);
    char char4 = str.charAt(3);

   
    int length = str.length();

    if(length < 5) {
        for(int ti = 0 ; ti <= (delay / 8) ; ti++){
            
            (1 > length) ? char1 = ' ' : char1 = str.charAt(0);
            (2 > length) ? char2 = ' ' : char2 = str.charAt(1);
            (3 > length) ? char3 = ' ' : char3 = str.charAt(2);
            (4 > length) ? char4 = ' ' : char4 = str.charAt(3);

            current_ms = millis();
            if(current_ms - previous_ms >= delay) { 
                print_digit(char1,pinD1);
            }

            previous_ms = current_ms;

            current_ms = millis();
            if(current_ms - previous_ms >= delay) { 
                print_digit(char2, pinD2);
            }

            previous_ms = current_ms;

            current_ms = millis();
            if(current_ms - previous_ms >= delay) { 
                print_digit(char3, pinD3);
            }

            previous_ms = current_ms;

            current_ms = millis();
            if(current_ms - previous_ms >= delay) { 
                print_digit(char4, pinD4);
            }
 
        }

    } else {
        /**
         *   if the string is more than 4 digits
         *  make the string move to show the full string 
         *   because the diplay fits 4 digits only)
         * */
        for(int t = 0 ; t <= length; t++){
            for(int ti = 0 ; ti <= (delay / 8) ; ti++){
            
                current_ms = millis();
                if(current_ms - previous_ms >= delay) { 
                    print_digit(char1,pinD1);
                }

                previous_ms = current_ms;

                current_ms = millis();
                if(current_ms - previous_ms >= delay) { 
                    print_digit(char2, pinD2);
                }

                previous_ms = current_ms;

                current_ms = millis();
                if(current_ms - previous_ms >= delay) { 
                    print_digit(char3, pinD3);
                }

                previous_ms = current_ms;

                current_ms = millis();
                if(current_ms - previous_ms >= delay) { 
                    print_digit(char4, pinD4);
                }

            }

            // empty display when movement finishes
            (t + 1 > length) ? char1 = ' ' : char1 = str.charAt(t);
            (t + 2 > length) ? char2 = ' ' : char2 = str.charAt(t);
            (t + 3 > length) ? char3 = ' ' : char3 = str.charAt(t);
            (t + 4 > length) ? char4 = ' ' : char4 = str.charAt(t);
        }
    }
}  

}
