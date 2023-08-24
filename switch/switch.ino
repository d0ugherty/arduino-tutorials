int switch_pin; //connect switch to digitial pin #2
int led_one, led_two, led_three, led_four;
int val;
int button_state;
int led_state;

void switch_leds();

void setup() {
    Serial.begin(9600);
    // initialize pins
    switch_pin = 2;
    led_one = 12;
    led_two = 11;
    led_three = 10;
    led_four = 9;
    
    pinMode(led_one, OUTPUT);
    pinMode(led_two, OUTPUT);
    pinMode(led_three, OUTPUT);
    pinMode(led_four, OUTPUT);

    pinMode(switch_pin, INPUT);
    led_state = 0;
    button_state = digitalRead(switch_pin);     // init button state as input value
}


void loop(){
    val = digitalRead(switch_pin);              // read input value
        if(val == LOW && val != button_state) { // check for change in button state 
            if(led_state == 0) {
                led_state = 1;
                Serial.println("button pressed");
                // turn LEDs either on or off
                digitalWrite(led_one, HIGH);
                digitalWrite(led_two, HIGH);
                digitalWrite(led_three, HIGH);
                digitalWrite(led_four, HIGH);
            } else {
                led_state = 0;
                digitalWrite(led_one, LOW);
                digitalWrite(led_two, LOW);
                digitalWrite(led_three, LOW);
                digitalWrite(led_four, LOW);
            }
        }

   button_state = val; // temporarily store button state
}
