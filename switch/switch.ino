int switch_pin = 2;     //connect switch to digitial pin #2
int val;
int button_state;



void setup() {
    Serial.begin(9600);
    pinMode(switch_pin, INPUT);

    button_state = digitalRead(switch_pin);     // init button state as input value
}


void loop(){
    val = digitalRead(switch_pin);              // read input value

    if(val != button_state) {                   // check if button state changed
        if(val == LOW) {                        // check if button is pressed
            Serial.println("Button pressed");
        } else if(val == HIGH) {
            Serial.println("Button released");
        }
    }
    button_state = val; // temporarily store button state
}
