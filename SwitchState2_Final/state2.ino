// This borrows code from Examples->EEPROM->eeprom_write

String textarray = "hello cornell tech!";
int endAddr;
int currentAddr = 0;

void state2Setup() {
//  digitalWrite(ledPin, LOW);
  Serial.println("Writing to EEPROM");
  
  //if any of the pin settings for the different states differed for the different states, you could change those settings here.
//  endAddr = min(textarray.length(), EEPROMSIZE);
//  for (int i = 0; i < endAddr; i++) {
//    EEPROM.write(i, textarray[i]);
//  }
  EEPROM.write(currentAddr, (analogRead(0)/4));
  currentAddr = currentAddr+1;
  Serial.println("value committed to EEPROM!");
 
}

void state2Loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void doState2() {
  if (lastState != 2) state2Setup();
  state2Loop();
}
