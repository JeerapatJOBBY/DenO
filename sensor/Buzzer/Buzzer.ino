void setup(){
    Serial.begin(9600);
    pinMode(2, INPUT_PULLUP);
}

void loop(){
    while (digitalRead(2)== 0) {
    tone(8,1000,100);
    }
}