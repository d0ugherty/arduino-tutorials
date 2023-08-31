/**
 * Helper functions for the 7-segment digital  display
 *
 */
#include "display.h"

namespace display {
bool mode = common_cathode;

//const int nbr_places = 4; //4 segments in the LED display
const int chars_count = 37;
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
    //Reset();
    
    int char_idx = -1;
    // search for character in array
    for(int i = 0; i < chars_count; i++) {
        if(digit == Char[i][8]) {
            char_idx = i;
        }
    }
    // turn off the pin if char is not found
    
    if(char_idx == -1) {
       digitalWrite(digit_port, !mode);
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
    int length = str.length();
    unsigned long previous_ms = millis();
    int currentDigit = 0;
    int currentState = 0;

    while (currentDigit < length) {
        unsigned long current_ms = millis();

        if (currentState == 0 && current_ms - previous_ms >= delay) {
            previous_ms = current_ms;
            char currentChar = str.charAt(currentDigit);
            print_digit(currentChar, pinD1 + currentDigit); // Assuming pinD1 is for the first digit
            currentState = 1;
            //currentDigit++;
        }

        if (currentState == 1 && current_ms - previous_ms >= delay) {
            previous_ms = current_ms;
            Reset(); // Replace this with the function to turn off the current digit display
            currentState = 0;
            currentDigit++;
        }
    }
}

}
