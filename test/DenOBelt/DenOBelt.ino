#include <Button.h>
#include <Keypad.h>
#include "SPI.h"
#include "MFRC522.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#define SS_PIN 10
#define RST_PIN 9
#define SP_PIN 8

MFRC522 rfid(SS_PIN, RST_PIN);//rfid

MFRC522::MIFARE_Key key;//rfid

Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);//oled

//keypad
Button button2(3);

const byte ROWS = 4; 
const byte COLS = 3;
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 2, 2}; 
byte colPins[COLS] = {8, 7, 6}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//keypad

long lasttimeStrateChange = 0;

void setup(){
    Serial.begin(9600);
    button2.begin();//buttonmodule
    pinMode(8, OUTPUT);
    SPI.begin();//rfid
    rfid.PCD_Init();//rdid
    oled.begin(0x3c);//oled
}


int Buttonnn = 0,NumberInKey = 0,FullCharge = 0,TIME=0,TimeTone = 0; //กำหนดตัวแปรในการดำเนินงาน
void loop()

{
    char key = keypad.getKey();
    long cuurrentTime = millis();

    if (button2.released()) {
    Buttonnn++;
    TIME++;
    tone(8,1000,100);

    oled.clearDisplay();
    oled.setCursor(10,15);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(2);
    oled.println("Press Num.");
    oled.display();

    }
    

    if (TIME >= 2)
    {
    oled.clearDisplay();
    oled.setCursor(40,10);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(3);
    oled.println("END");
    
    oled.display();
        TIME=0;
        Buttonnn=0;
    }

    //กำหนดค่าตอนกดปุ่มกับตอนกด keypad
    if (key =='1') {
    NumberInKey=1;
    }
    if (key =='2') {
    NumberInKey=2;
    }
    if (key == '3'){
    NumberInKey=3;
    }
    if (key == '4'){
    NumberInKey=4;
    }
       

    //เริ่มการทำงานพอร์มที่ 1 sword form
    if (Buttonnn == 0)
    {
        NumberInKey=0;
    }
    if (Buttonnn==1 && NumberInKey==1)
    {
        if (NumberInKey == 1 )
        {
        oled.clearDisplay();
        oled.setCursor(10,10);
        oled.setTextColor(SSD1306_WHITE);
        oled.setTextSize(2);
        oled.println("Scan card");
        oled.display();
        

        if ( TimeTone ==0 & cuurrentTime - lasttimeStrateChange >= 200){
        tone(8,1000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 1;
        }
        if ( TimeTone ==1 & cuurrentTime - lasttimeStrateChange >= 200){
        tone(8,500,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 2;
        }
        if ( TimeTone ==2 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,1000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 3;
        }
        if ( TimeTone ==3 & cuurrentTime - lasttimeStrateChange >= 200){
        tone(8,500,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 4;
        }
        if ( TimeTone ==4 & cuurrentTime - lasttimeStrateChange >= 200){
        tone(8,1000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 5;
        }
        if ( TimeTone ==5 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,600,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 6;
        }
        if ( TimeTone ==6 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,700,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 7;
        }
        if ( TimeTone ==7 & cuurrentTime - lasttimeStrateChange >= 200){
        tone(8,800,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 0;
        }

        }
            //กำหนดค่า RFID

            if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
                return; 

                String strID = "";
                for (byte i = 0; i < 4; i++) 
                    {
                        strID +=(rfid.uid.uidByte[i] < 0x10 ? "0" : "") + String(rfid.uid.uidByte[i], HEX) + (i!=3 ? ":" : "");
                    }
            strID.toUpperCase();
    
          
    if (strID == "04:AA:89:2B") 
    {
    noTone(8);

    delay(250);
    tone(8,500,50);
    delay(100);
    tone(8,1000,100);


    oled.clearDisplay();
    oled.setCursor(0,10);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(3);
    oled.println("HENSHIN");
    oled.display();

    delay(2000);

    for(int x = 1 ;x <= 150;x++)
    {
    oled.clearDisplay();
    oled.setCursor(x-150,18);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(2);
    oled.print("SWORD FORM");
    tone(8,100,1000);

    oled.setCursor(x,18);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(2);
    oled.print("SWORD FORM");
    
    oled.display();

    tone(8,x+100,1000);
    }

    FullCharge=1;
    NumberInKey=0;
    }




  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
    }//จบพอร์มที่ 1


    //เริ่มการทำงาน 2
    if (Buttonnn == 0)
    {
        NumberInKey=0;
    }
    if (Buttonnn==1 && NumberInKey==2)
    {
        if (NumberInKey == 2)
        {
        oled.clearDisplay();
        oled.setCursor(10,10);
        oled.setTextColor(SSD1306_WHITE);
        oled.setTextSize(2);
        oled.println("Scan card");
        oled.display();

        if ( TimeTone ==0 & cuurrentTime - lasttimeStrateChange >= 200){
        tone(8,1600,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 1;
        }
        if ( TimeTone ==1 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,2000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 2;
        }
        if ( TimeTone ==2 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,1700,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 3;
        }
        if ( TimeTone ==3 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,2000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 4;
        }
        if ( TimeTone ==4 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,1700,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 5;
        }
        if ( TimeTone ==5 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,2000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 6;
        }
        if ( TimeTone ==6 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,1600,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 7;
        }
        if ( TimeTone ==7 & cuurrentTime - lasttimeStrateChange >= 200){
        tone(8,2100,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 0;
        }
        }

            //กำหนดค่า RFID

            if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
                return; 

                String strID = "";
                for (byte i = 0; i < 4; i++) 
                    {
                        strID +=(rfid.uid.uidByte[i] < 0x10 ? "0" : "") + String(rfid.uid.uidByte[i], HEX) + (i!=3 ? ":" : "");
                    }
            strID.toUpperCase();
            
    if (strID == "04:AA:89:2B") 
    {
    noTone(8);

    delay(250);
    tone(8,500,50);
    delay(100);
    tone(8,1000,100);


    oled.clearDisplay();
    oled.setCursor(0,10);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(3);
    oled.println("HENSHIN");
    oled.display();

    delay(2000);

    for(int x = 1 ;x <= 150;x++)
    {
    oled.clearDisplay();
    oled.setCursor(x-150,18);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(2);
    oled.print("SPEAR FORM");
    tone(8,100,1000);

    oled.setCursor(x,18);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(2);
    oled.print("SPEAR FORM");
    
    oled.display();

    tone(8,x+100,1000);
    }

    FullCharge=1;
    NumberInKey=0;
    }
    

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
        }//จบพอร์มที่ 2

    //เริ่มการทำงานพอร์มที่ 3 sword form
    if (Buttonnn == 0)
    {
        NumberInKey=0;
    }
    if (Buttonnn==1 && NumberInKey==3)
    {
        if (NumberInKey == 3)
        {
        oled.clearDisplay();
        oled.setCursor(10,10);
        oled.setTextColor(SSD1306_WHITE);
        oled.setTextSize(2);
        oled.println("Scan card");
        oled.display();
        
        if ( TimeTone ==0 & cuurrentTime - lasttimeStrateChange >= 300){
        tone(8,600,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 1;
        }
        if ( TimeTone ==1 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,100,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 2;
        }
        if ( TimeTone ==2 & cuurrentTime - lasttimeStrateChange >= 300){
        tone(8,200,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 3;
        }
        if ( TimeTone ==3 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,300,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 4;
        }
        if ( TimeTone ==4 & cuurrentTime - lasttimeStrateChange >= 500){
        tone(8,600,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 5;
        }
        if ( TimeTone ==5 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,400,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 6;
        }
        if ( TimeTone ==6 & cuurrentTime - lasttimeStrateChange >= 100){
        tone(8,500,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 7;
        }
        if ( TimeTone ==7 & cuurrentTime - lasttimeStrateChange >= 200){
        tone(8,600,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 0;
        }
        }
            //กำหนดค่า RFID

            if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
                return; 

                String strID = "";
                for (byte i = 0; i < 4; i++) 
                    {
                        strID +=(rfid.uid.uidByte[i] < 0x10 ? "0" : "") + String(rfid.uid.uidByte[i], HEX) + (i!=3 ? ":" : "");
                    }
            strID.toUpperCase();
          
    if (strID == "04:AA:89:2B") 
    {
    noTone(8);

    delay(250);
    tone(8,500,50);
    delay(100);
    tone(8,1000,100);


    oled.clearDisplay();
    oled.setCursor(0,10);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(3);
    oled.println("HENSHIN");
    oled.display();

    delay(2000);

    for(int x = 1 ;x <= 150;x++)
    {
    oled.clearDisplay();
    oled.setCursor(x-150,18);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(2);
    oled.print("AXE FORM");
    tone(8,100,1000);

    oled.setCursor(x,18);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(2);
    oled.print("AXE FORM");
    
    oled.display();

    tone(8,x+100,1000);
    }

    FullCharge=1;
    NumberInKey=0;
    }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
    }//จบพอร์มที่ 3

    //เริ่มการทำงานพอร์มที่ 4 sword form
    if (Buttonnn == 0)
    {
        NumberInKey=0;
    }
    if (Buttonnn==1 && NumberInKey==4)
    {
        if(NumberInKey == 4)
        {
        oled.clearDisplay();
        oled.setCursor(10,10);
        oled.setTextColor(SSD1306_WHITE);
        oled.setTextSize(2);
        oled.println("Scan card");
        oled.display();

        if ( TimeTone ==0 & cuurrentTime - lasttimeStrateChange >= 150){
        tone(8,2000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 1;
        }
        if ( TimeTone ==1 & cuurrentTime - lasttimeStrateChange >= 150){
        tone(8,1000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 2;
        }
        if ( TimeTone ==2 & cuurrentTime - lasttimeStrateChange >= 75){
        tone(8,2000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 3;
        }
        if ( TimeTone ==3 & cuurrentTime - lasttimeStrateChange >= 150){
        tone(8,1000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 4;
        }
        if ( TimeTone ==4 & cuurrentTime - lasttimeStrateChange >= 150){
        tone(8,1200,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 5;
        }
        if ( TimeTone ==5 & cuurrentTime - lasttimeStrateChange >= 75){
        tone(8,1000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 6;
        }
        if ( TimeTone ==6 & cuurrentTime - lasttimeStrateChange >= 75){
        tone(8,2000,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 7;
        }
        if ( TimeTone ==7 & cuurrentTime - lasttimeStrateChange >= 150){
        tone(8,1200,400);
        lasttimeStrateChange = cuurrentTime;
        TimeTone = 0;
        }
        }
            //กำหนดค่า RFID

            if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
                return; 

                String strID = "";
                for (byte i = 0; i < 4; i++) 
                    {
                        strID +=(rfid.uid.uidByte[i] < 0x10 ? "0" : "") + String(rfid.uid.uidByte[i], HEX) + (i!=3 ? ":" : "");
                    }
            strID.toUpperCase();

    if (strID == "04:AA:89:2B") 
    {
    noTone(8);

    delay(250);
    tone(8,500,50);
    delay(100);
    tone(8,1000,100);


    oled.clearDisplay();
    oled.setCursor(0,10);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(3);
    oled.println("HENSHIN");
    oled.display();

    delay(2000);

    for(int x = 1 ;x <= 150;x++)
    {
    oled.clearDisplay();
    oled.setCursor(x-150,18);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(2);
    oled.print("GUN FORM");
    tone(8,100,1000);

    oled.setCursor(x,18);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(2);
    oled.print("GUN FORM");
    
    oled.display();

    tone(8,x+100,1000);
    }

    FullCharge=1;
    NumberInKey=0;
    }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
    }//จบพอร์มที่ 4


    //ใช้ Fullchange
    if (FullCharge == 1)
    {
        if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
                return; 

                String strID = "";
                for (byte i = 0; i < 4; i++) 
                    {
                        strID +=(rfid.uid.uidByte[i] < 0x10 ? "0" : "") + String(rfid.uid.uidByte[i], HEX) + (i!=3 ? ":" : "");
                    }
            strID.toUpperCase();

        if (strID == "69:C1:A0:C2")
        {
            delay(250);
            tone(8,500,50);
            delay(100);
            tone(8,1000,100);

        for(int x = 1 ;x <= 150;x++)
        {
            oled.clearDisplay();
            oled.setCursor(x-150,18);
            oled.setTextColor(SSD1306_WHITE);
            oled.setTextSize(2);
            oled.print("FULLCHANGE");

            oled.setCursor(x,18);
            oled.setTextColor(SSD1306_WHITE);
            oled.setTextSize(2);
            oled.print("FULLCHANGE");
    
            oled.display();

            tone(8,x*10,1000);
        }

            FullCharge = 0;
        }
    }

}