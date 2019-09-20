# Data Logger (and using cool sensors!)

*A lab report by MAtt. W. Freed

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
One solution to use the RGB would be to display different colors during different states in compact scenarios

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

### 3. IR Proximity Sensor
  
  No Proximity Sensor was supplied
  
**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?**

**b. Upload your merged code to your lab report repository and link to it here.**

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
