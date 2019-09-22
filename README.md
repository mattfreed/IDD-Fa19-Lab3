# Data Logger (and using cool sensors!)

A lab report by Matt. W. Freed

## In The Report

Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

 0 to 1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

It has a 10 bit ADC (which means it can detect 2^10 analog levels)

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**
One solution to use the RGB would be to display different colors during different states when ussing the accelerometer

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

The values range between 0-1006 when not pressed and pressed hard (had a resistance value of 20K ohms)

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

The voltage drop is linear. The more force applied, the less resistance, providing more signal power to the analog input pin.

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

You can use an arduino Map function that maps the values of 0-1000 to 50-255 (50 is about where the LED is almost able to light up)

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

Flex Sensor:66Kohm (3x 22k Ohm) for a range of 400-750

PhotoResistor: 10K ohm for a range of 400-900

SoftPot: 2 10K ohms in series (1 before power input and one after)

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

These sensors have a linear response

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

[Code](/accelReadout.ino)

### 3. IR Proximity Sensor
  
  No Proximity Sensor was supplied
  
**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?**

**b. Upload your merged code to your lab report repository and link to it here.**

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

[Code for accel readout on display](/accelReadout_Oled.ino)
## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

It does matter which actions are assigned to each state, since each state represents the next action in sequential order. If they were randomly assigned, they would not be in the right order.

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

They are in setup because we only want the action to happen once, not continually write/clear to the eeprom

**c. How many byte-sized data samples can you store on the Atmega328?**

It can hold 1024 byte sized data samples since it has 1024 bytes of internal EEPROM Memory

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

Each byte on the eeprom can only a value between 0 to 255, so you would have to take the analog value of 0 to 1023 and divide by 4.

IC2 devices only send one byte at a time



**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

We would occupy multiple addresses in the EEPROM and start our write from the end of the last byte stored. This works even for custom data types. The data would then be stored together from byte x to (x+data size)

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

[Modified Code Location](https://github.com/mattfreed/IDD-Fa19-Lab3/tree/master/SwitchState2_Final)

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

![StateDiagram](/WalkSensor.png)

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**

This data logger logs the force of your foot on the floor throughout a stepping motion. It writes and reads to the onboard memory of the arduino.


