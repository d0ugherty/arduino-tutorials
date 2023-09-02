#ifndef DISPLAY_H
#define DISPLAY_H

#include "pins.h"
#include "digits.h"

namespace display {
    void reset();
    void display_digit(int number);
    void display_number(int number);
}

#endif
