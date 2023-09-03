#include "display.h"
#include "pins.h"

namespace display {
    void reset() {
        for(int i = 0; i < seg_pins.size(); i++){
            digitalWrite(seg_pins[i], LOW));
        }
    }

    void display_digit(int number) {
    }

    void display_number(int number) {
    }
}
