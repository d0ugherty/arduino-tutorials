/**
 * Analog sensor on the board reads voltage from the analog pin
 * and converts that into a digital format that can be read by 
 * the microcontroller.
 * 
 *  Input voltage gets fed to the board's analog pin through a voltage
 *  divider made by two resistors. A voltage divider is an electrical 
 *  circuit that consists of two or more resistive components connected 
 *  in series to divide a voltage into smaller parts.
 * 
 * 
 *  Vsensor_input = 5V x [R1 / (R1 + 1kohm)]
 * 
 *  Output voltage is determined by the relative values of the resistors.
 * 
 * TO DO: Set this up the 4-digit 7-segment display
*/

int analog_pin;
int sensor_value;   // variable to store the value coming from the sensor
float sensor_voltage; // variable to store the voltage coming from the sensor

void setup(){
    analog_pin = A0;
    Serial.begin(9600);
}

void loop() { 
    sensor_value = analogRead(analog_pin);
    sensor_voltage = sensor_value * (5.0 / 1023.0);

    Serial.print("Voltage: ");
    Serial.println(sensor_voltage);
    
    delay(1000);
}

