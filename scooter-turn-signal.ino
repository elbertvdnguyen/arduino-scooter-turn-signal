3#include <LedControl.h>

#include <Adafruit_GrayOLED.h>
#include <gfxfont.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <SPI.h>

// settings pins

int Din = 11;
int CLK = 13;
int CS = 10;

#define joystick A0

LedControl turnSignalDisplay = LedControl(Din,CLK,CS,0);

// old setup implementation (utilizing Max72xxPanel + Adafruit GFX libraries)
// 
// int numberOfHorizontalDisplays = 1;
// int numberOfVerticalDisplays = 1;
//
// Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);
//
// const unsigned char PROGMEM leftTurnSignal[] = {
//  B00010000, // row 1
//  B00100000, // row 2
//  B01000000, // row 3
//  B11111111, // row 4
//  B11111111, // row 5
//  B01000000, // row 6
//  B00100000, // row 7
//  B00010000  // row 8
// };
//
//const unsigned char PROGMEM rightTurnSignal[] = {
//  B00001000, // row 1
//  B00000100, // row 2
//  B00000010, // row 3
//  B11111111, // row 4
//  B11111111, // row 5
//  B00000010, // row 6
//  B00000100, // row 7
//  B00001000  // row 8
// };
//
// const unsigned char PROGMEM empty[] = {
//  B00000000,
//  B00000000,
//  B00000000,
//  B00000000,
//  B00000000,
//  B00000000,
//  B00000000,
//  B00000000
// };
// 
// TL;DR - bitmaps above would have been outputted onto matrix using drawBitmap(...) and write() in loop()

byte rightTurn[8] = {0x10,0x20,0x40,0xFF,0xFF,0x40,0x20,0x10}; // matrix layout for right arrow
byte leftTurn[8] = {0x08,0x04,0x02,0xFF,0xFF,0x02,0x04,0x08}; // matrix layout for left arrow

void printByte(byte character []) {
  int i = 0;
    for(i=0;i<8;i++) {
      turnSignalDisplay.setRow(0,i,character[i]);
    }
}

void setup() {
  
    Serial.begin(9600); // DEBUGGING PURPOSES ONLY
    // setting input pins
    // pinMode(leftSignal, INPUT);
    // pinMode(rightSignal, INPUT);

    // matrix bootup
    // this was followed on guidance of the following Instructables guide: https://www.instructables.com/DOT-Matrix-8x8-Using-Arduino/
    turnSignalDisplay.shutdown(0, false); // keeps LED matrix out of power-save (i.e., sleep)
    turnSignalDisplay.setIntensity(0, 15); // sets the display brightness to max
    turnSignalDisplay.clearDisplay(0); // clears LED matrix
}

void leftTurnSignal() {
//  turnSignalDisplay.shutdown(0, false); // takes LED matrix out of power-save (i.e., sleep)
//  turnSignalDisplay.setIntensity(0, 15); // sets the display brightness to max
//  turnSignalDisplay.clearDisplay(0); // clears LED matrix
  for (int i = 0; i < 20; i++) {
    printByte(leftTurn);
    delay(200);
    turnSignalDisplay.clearDisplay(0); // clears LED matrix
    delay(200);
  }
//  turnSignalDisplay.shutdown(0,true);
}

void rightTurnSignal() {
//  turnSignalDisplay.shutdown(0, false); // takes LED matrix out of power-save (i.e., sleep)
//  turnSignalDisplay.setIntensity(0, 15); // sets the display brightness to max
//  turnSignalDisplay.clearDisplay(0); // clears LED matrix
  for (int i = 0; i < 20; i++) {
    printByte(rightTurn);
    delay(200);
    turnSignalDisplay.clearDisplay(0); // clears LED matrix
    delay(200);
  }
//  turnSignalDisplay.shutdown(0,true);
}

void loop() {
  turnSignalDisplay.clearDisplay(0); // clears LED matrix
  
  int joystickX = analogRead(A0);
  
//  Serial.print("X = ");
//  Serial.print(joystickX);
//  delay(5000);
  
  if (joystickX < 300) {
    leftTurnSignal();
//    turnSignalDisplay.shutdown(0, false); // takes LED matrix out of power-save (i.e., sleep)
//    turnSignalDisplay.setIntensity(0, 15); // sets the display brightness to max
//    turnSignalDisplay.clearDisplay(0); // clears LED matrix
//    
//    // Serial.print("Left button pressed. "); // DEBUGGING PURPOSES ONLY
//    printByte(leftTurn);
//    delay(5000);
//    turnSignalDisplay.clearDisplay(0); // clears LED matrix
//    leftTurnPressed = LOW;
//    // turnSignalDisplay.shutdown(0,true);
  }
//
  else if (joystickX > 400) {
    rightTurnSignal();
//    turnSignalDisplay.shutdown(0, false); // takes LED matrix out of power-save (i.e., sleep)
//    turnSignalDisplay.setIntensity(0, 15); // sets the display brightness to max
//    turnSignalDisplay.clearDisplay(0); // clears LED matrix
//    
//    // Serial.print("Right button pressed. "); // DEBUGGING PURPOSES ONLY
//    printByte(rightTurn);
//    delay(5000);
//    turnSignalDisplay.clearDisplay(0); // clears LED matrix
//    rightTurnPressed = LOW;
//    // turnSignalDisplay.shutdown(0,true);
  }

  else if ((joystickX >= 300) && (joystickX <= 400)) {
    turnSignalDisplay.clearDisplay(0);
  }
  // turnSignalDisplay.shutdown(0,true); // shuts off upon completion to save power/energy
}
