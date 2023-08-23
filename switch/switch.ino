int switch_pin = 2;     //connect switch to digitial pin #2
int led_pin = 12;
int volt;
void setup() {
    //Serial.begin(9600);
    pinMode(led_pin, OUTPUT);
    pinMode(switch_pin, INPUT);
}


void loop(){
    volt = digitalRead(switch_pin);
    if(volt == LOW) {
        digitalWrite(led_pin, HIGH);
        delay(100);
        digitalWrite(led_pin, LOW);
        delay(100);
    } else if(volt == HIGH) {
     //   Serial.println("Button pressed");
        digitalWrite(led_pin, LOW);
    }
}

