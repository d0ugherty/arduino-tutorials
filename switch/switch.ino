int switch_pin = 2;     //connect switch to digitial pin #2
int volt;
void setup() {
    Serial.begin(9600);
    pinMode(switch_pin, INPUT);
    Serial.println("start");
}


void loop(){
    volt = digitalRead(switch_pin);
    if(volt == HIGH){
        Serial.println("Button pressed");
    } else {
        Serial.println("Button released");
    }
    delay(100);
}
