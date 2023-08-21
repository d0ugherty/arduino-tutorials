// hello world
//  playing with resistors
int bluePin = 13;
int greenPin = 12;
int redPin = 11;

void setup(){
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(redPin, OUTPUT);
}


void loop(){
    digitalWrite(bluePin, HIGH);
    //delay(100);
    digitalWrite(greenPin, LOW);
    //delay(100);
    digitalWrite(redPin, HIGH);
    delay(200);
     digitalWrite(bluePin, LOW);
    //delay(100);
    digitalWrite(greenPin, HIGH);
   // delay(100);
    digitalWrite(redPin, LOW);
    delay(200);
}

