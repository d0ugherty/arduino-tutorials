//A potentiometer is a simple mechanical device that provides a varying amount of resistance when its shaft is turned


void setup(){
    //initialize communication at 9600 bits per second
    Serial.begin(9600);
}

void loop(){
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    delay(250);
}