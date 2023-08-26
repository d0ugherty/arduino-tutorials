/**
 * Helper functions for the 7-segment digital  display
 *
 */
#include "display.h"

namespace display {
bool mode = common_anode;

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
    char char1 = str.charAt(0);
    char char2 = str.charAt(1);
    char char3 = str.charAt(2);
    char char4 = str.charAt(3);

    char char1_num = 0;
    char char2_num = 0;
    char char3_num = 0;
    char char4_num = 0;

    int length = str.length();

    if(length < 5) {
        for(int ti = 0 ; ti <= (delay / 8) ; ti++){
            
            if(1 > length) {
                char1 = ' ';
            } else {
                char1 = str.charAt(0);
            }

            if(2 > length) {
                char2 = ' ';
            } else {
                char2 = str.charAt(1);
            }
            
            if(3 > length) {
                char3 = ' ';
            } else {
                char3 = str.charAt(2);
            }

            if(4 > length) {
                char4 = ' ';
            } else {
                char4 = str.charAt(3);
            }


        
            print_digit(char1,pinD1);
            millis();             

            print_digit(char2,pinD2);
            millis();
            //delay(2);

            print_digit(char3,pinD3);
            millis();
            //delay(2);

            print_digit(char4,pinD4);
            millis();
            //delay(2);
 
        }

    } else {
        /**
         *   if the string is more than 4 digits
         *  make the string move to show the full string 
         *   because the diplay fits 4 digits only)
         * */
        for(int t = 0 ; t <= length; t++){
            for(int ti = 0 ; ti <= (delay / 8) ; ti++){

                print_digit(char1,pinD1);
               // delay(2);
               millis(); 
                print_digit(char2,pinD2);
               // delay(2);
                millis();
                print_digit(char3,pinD3);
              //  delay(2);
                millis();
                print_digit(char4,pinD4);
              //  delay(2);
            }

            // empty display when movement finishes
             if(t + 1 > length) char1 = ' ';
             else char1 = str.charAt(t);
             if((t + 2) > length) char2 = ' ';
             else char2 = str.charAt(t + 1);
             if((t + 3) > length) char3 = ' ';
             else char3 = str.charAt(t + 2);
             if((t + 4) > length) char4 = ' ';
             else char4 = str.charAt(t + 3);
        }
    }
}  

}