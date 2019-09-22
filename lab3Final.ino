
#include <EEPROM.h>

/** the current address in the EEPROM (i.e. which byte we're going to write to next) **/
int addr = 0;
int address = 0;
byte valueRead;

int logVal = 13;
int readVal = 12;

void setup() {
  Serial.begin(9600);
  pinMode(logVal, INPUT);
  pinMode(readVal, INPUT);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
}

void loop() {

  if(digitalRead(logVal) == HIGH){
    int val = analogRead(A0);
    int inputValue = val/4;

    EEPROM.write(addr, inputValue);
  addr = addr + 1;
  if (addr == EEPROM.length()) {
    addr = 0;
  }
  delay(100);
  }
  
  if(digitalRead(readVal) == HIGH){
    valueRead = EEPROM.read(address);
    Serial.print(address);
    Serial.print("\t");
    Serial.print(valueRead, DEC);
    Serial.println();

      address = address + 1;
  if (address == EEPROM.length()) {
    address = 0;
   delay(500);
    }
  }
  





}
