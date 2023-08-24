int switch_pin = 2;     //connect switch to digitial pin #2
int led_pin12 = 12;
int led_pin11 = 11;
int volt;
int count;

void flash (int pin);

void setup() {
    Serial.begin(9600);
    pinMode(led_pin12, OUTPUT);
    pinMode(led_pin11, OUTPUT);
    pinMode(switch_pin, INPUT);
}


void loop(){
    volt = digitalRead(switch_pin);
    if(volt == LOW) {
        flash(led_pin12);
    } else if(volt == HIGH) {
        digitalWrite(led_pin11, HIGH);
        digitalWrite(led_pin12, LOW);
    }
}

void flash(int pin){
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(100);
}
