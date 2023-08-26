/**
 * Helper functions for the 7-segment digital  display
 *
 */
#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include "array.h"

namespace display {
    void Reset();
    void print_digit(char digit, int digit_port);
    void print_display(String str, int delay); 
}

#endif
