#include <EEPROM.h>
int buttonPin = 7;
int ledPin = 9;
int led_status;
int buttonState = 0;
byte buffmy[50];
int readDatamy = 0;

uint8_t EEPROMaddress = 1;

void setup(){
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    led_status = EEPROM.read(EEPROMaddress);
    Serial.begin(115200);
  Serial1.begin(115200);
}

void _light(){
  if(led_status == 1)
    _sw_on();
  else
    _sw_off();
}

void _switch(){   
    buttonState = digitalRead(buttonPin);
    
    if (buttonState == HIGH){
         if (led_status == 1){
             led_status = 0;
             EEPROM.write(EEPROMaddress, led_status);
             _sw_off();
         }
         else{
             led_status = 1;
             EEPROM.write(EEPROMaddress, led_status);
             _sw_on();
         }
         delay(100);
    }
}

void _sw_on(){
  digitalWrite(ledPin, HIGH);
}

void _sw_off(){
  digitalWrite(ledPin, LOW);
}

void readmySerial() {
  delay(100);
  while (Serial1.available()) {
    buffmy[readDatamy++] = (byte)Serial1.read();
    if(readDatamy > 50){
      readDatamy = 0;
    }
  }
}

void _switch_serial(){
  if(readDatamy > 0) {
      if(buffmy[15] == '0' && buffmy[16] == '0')
      { 
        if(buffmy[17] == '0'){
          led_status = 0;
          EEPROM.write(EEPROMaddress, led_status);
          _sw_off();
          Serial.print("LED OFF");
        }else{
          led_status = 1;
          EEPROM.write(EEPROMaddress, led_status);
          _sw_on();
          Serial.print("LED ON");
        }
      }
    readDatamy = 0;
  }
  
}

void loop(){
    _light();
    _switch();
    readmySerial();
    _switch_serial();
}


