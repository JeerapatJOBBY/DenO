#include <Button.h>


Button button3(4);

void setup()
{
    Serial.begin(9600);
    button3.begin();
    
}


void loop(){
    while (button3.pressed()) 
    {
    Serial.println("Hello");
    }
    Serial.println("NOTHING");

}