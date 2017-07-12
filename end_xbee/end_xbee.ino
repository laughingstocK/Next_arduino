
byte buff[50];
int readData = 0;
byte buffmy[50];
int readDatamy = 0;

  
void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  readmySerial();
  if(readDatamy > 0) {
      if(buffmy[15] == '0' && buffmy[16] == '0')
      { 
        if(buffmy[17] == '0'){
          Serial.print("LED OFF");
        }else{
          Serial.print("LED ON");
        }
      }
    readDatamy = 0;
  }
}

void readSerial() {
  delay(100);
  while (Serial.available()) {
    buff[readData++] = (byte)Serial.read();
    if(readData > 50){
      readData = 0;
    }
  }
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


