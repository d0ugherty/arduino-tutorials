int switch_pin = 2;     //connect switch to digitial pin #2

void setup(){

    Serial.begin(9600);             // 9600 bps
    pinMode(switch_pin, INPUT);     // use switch as input
}


void loop(){
    Serial.print("Read input...");
    Serial.println(digitalRead(switch_pin));
    delay(250);
}
