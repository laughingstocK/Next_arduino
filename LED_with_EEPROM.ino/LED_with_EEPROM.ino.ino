#include <EEPROM.h>
int buttonPin = 7;
int ledPin = 9;
int led_status;
int buttonState = 0;

int buttonPushCounter = 0;
int lastButtonState = 0;
int lastPress = 0;
uint8_t EEPROMaddress = 1;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    led_status = EEPROM.read(EEPROMaddress); 
    Serial.begin(9600);
}

void _light()
{
  if(led_status == 1)
  {
    _sw_on();
  }else
  {
    _sw_off();
  }
}

void _switch()
{   
    buttonState = digitalRead(buttonPin);
    
    if (buttonState == HIGH)
    {

         if (led_status == 1)
         {
             led_status = 0;
             EEPROM.write(EEPROMaddress, led_status);
             _sw_off();
         }
         else
         {
             led_status = 1;
             EEPROM.write(EEPROMaddress, led_status);
             _sw_on();
         }
         delay(500);
    }
}

void _sw_on(){
  digitalWrite(ledPin, HIGH);
}

void _sw_off(){
  digitalWrite(ledPin, LOW);
}

void loop()
{
    _light();
    _switch();
}

