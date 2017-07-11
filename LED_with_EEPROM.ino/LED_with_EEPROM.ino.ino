#include<EEPROM.h>
int buttonPin = 7;
int ledPin = 9;
boolean on;
int buttonState = 0;

int buttonPushCounter = 0;
int lastButtonState = 0;
int lastPress = 0;
uint8_t EEPROMaddress = 130;
  
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  lastPress = EEPROM.read(EEPROMaddress);
  buttonState = digitalRead(buttonPin);

  if(on == true){
    lastPress = on;
    EEPROM.write(EEPROMaddress,lastPress);
    }
    else if(on == false){
    lastPress = on;
    EEPROM.write(EEPROMaddress,lastPress);
    }
  
  if(buttonState == HIGH){
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounter);
    if(on==true){
        on = false;
      }else{
        on = true;
      }
    }
    
    if(on == true){
        digitalWrite(ledPin,HIGH);
      }
      else{
        digitalWrite(ledPin,LOW);
      }

        delay(200);
}
