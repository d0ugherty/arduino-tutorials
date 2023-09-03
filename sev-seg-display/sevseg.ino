#include "pins.h"
#include "display.h"

int sensor_value;
int voltage_int;
float sensor_voltage;

void setup() {
    setup_display(); 
    Serial.begin(9600);
}

void loop() {
    sensor_value = analogRead(A0);
    
    //using a single digit display, we can start with only showing an int
    voltage_int = sensor_value * (5.0 / 1023.0);
    
    //put function call to the display the number here
    
    delay(500);
}

void setup_display(){
   for(int i = 0; i < seg_pins.length(); i++) {
       pinMode(seg_pins[i], OUTPUT);
   }
}

