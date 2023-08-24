int switch_pin; //connect switch to digitial pin #2
int led_one, led_two, led_three, led_four;
int val;
int button_state, led_state;
int light_mode;
bool light_on;

void switch_leds();
bool bounce();

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
    led_state = LOW;
    light_mode = 0;
    button_state = digitalRead(switch_pin);     // init button state as input value
}


void loop(){
    val = digitalRead(switch_pin);                              // read input value
    if(val == LOW && val != button_state && !bounce()) {    // check for change in button state 
        light_mode++;
        Serial.println(light_mode);
    }
    
    switch(light_mode % 4) {
        case 1:     // flash
            switch_leds();
            delay(100);
            break;

        case 2:     // All lights on
            digitalWrite(led_one, HIGH);
            digitalWrite(led_two, HIGH);
            digitalWrite(led_three, HIGH);
            digitalWrite(led_four, HIGH);
            break;

        case 3:     // wave
            if(val == HIGH) {
                digitalWrite(led_four, LOW);
                digitalWrite(led_one, HIGH);
                
                delay(75);
                
                digitalWrite(led_one, LOW);
                digitalWrite(led_two, HIGH);
                
                delay(75);

                digitalWrite(led_two, LOW);
                digitalWrite(led_three, HIGH);
                
                delay(75);

                digitalWrite(led_three, LOW);
                digitalWrite(led_four, HIGH);

                delay(75);

                digitalWrite(led_four, LOW);
            }
            break;
     
        default:   // off
            digitalWrite(led_one, LOW);
            digitalWrite(led_two, LOW);
            digitalWrite(led_three, LOW);
            digitalWrite(led_four, LOW);
        }   

    button_state = val; // temporarily store button state
}
/*
* By reading two values with a delay, we can detect if the spring
* inside the button switch has bounced or not, helping give more accurate
* input. 
**/
bool bounce(){
    int val1 = digitalRead(switch_pin);
    delay(10);
    int val2 = digitalRead(switch_pin);
    return val1 != val2;
}

void switch_leds(){
//turn the LEDs either on or off
    digitalWrite(led_one, ~led_state);
    digitalWrite(led_two, ~led_state);
    digitalWrite(led_three, ~led_state);
    digitalWrite(led_four, ~led_state);
    led_state = ~led_state;
}
