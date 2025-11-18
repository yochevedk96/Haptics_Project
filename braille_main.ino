#include "letter_dictionary.h"

const int dirPins[6]  = {2, 3, 4, 5, 6, 7};
const int stepPins[6] = {8, 9, 10, 11, 12, 13};

char state[6] = {'d', 'd', 'd', 'd', 'd', 'd'};

int stepsPerRevolution = 2000; // Typical for 1.8° motors
const int stepDelay = 500;         // Microseconds between steps (speed control)

LetterDictionary dict;
String new_string = "you've got braille!";
char charArray[20];
int buttonState = 0; 
int letter = 0;
const int buttonPin = A1;     // the number of the pushbutton pin

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  pinMode(buttonPin, INPUT_PULLUP);
  for (int i = 0; i < 6; i++) {
    pinMode(dirPins[i], OUTPUT);
    pinMode(stepPins[i], OUTPUT);
    digitalWrite(stepPins[i], LOW);
    digitalWrite(dirPins[i], LOW);
  }

  new_string.toUpperCase();
  new_string.toCharArray(charArray, new_string.length() + 1);
  Serial.print("Converting to braille the word: ");
  Serial.println(new_string);
//
//  while(!Serial){
//    ;
//  }
//  
//  Serial.println("Please enter a word to convert to braille and hit ENTER");
//
//  while (new_string.length() == 0) {
//    if (Serial.available()) {}
//      new_string = Serial.readStringUntil('\n');
//      new_string.trim();
//      new_string.toUpperCase();
//      new_string.toCharArray(charArray, new_string.length() + 1);
//      Serial.print("Converting to braille the word: ");
//      Serial.println(new_string);
//  }

}

void loop() {

  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    //Serial.println("Button is Low, do nothing");
  } else {
    if (letter+1 == new_string.length()) {
      Serial.println("Sring is finished, starting from the beggining");
      resetAllPinsToDown();
      letter = 0;
    }
  
    Serial.println("Button is Pressed: ");
    //THIS IS WHERE OUR CODE BEGINS
    //get the next letter in the array
    char this_letter = charArray[letter];
    char* values = dict.getValuesForLetter(this_letter);

   if (values != nullptr) {
      Serial.print("Commanding motors for the letter: ");
      Serial.println(this_letter);
    } else {
      Serial.print(" :( No value for character: ");
      Serial.println(this_letter);
    }
    
    //program the next letter
    moveAllMotorsTogether(values, stepsPerRevolution);
    
    letter++;
    
  }

}


void moveAllMotorsTogether(char target[6], int steps)
{
  // set direction on each motor
  for (int i = 0; i < 6; i++) {
    if (state[i] != target[i]) {
      int dirSignal = (target[i] == 'u') ? HIGH : LOW;
      digitalWrite(dirPins[i], dirSignal);
    }
  }

  // move all required motors together
  for (int s = 0; s < steps; s++) {

    // step HIGH for all required motors
    for (int i = 0; i < 6; i++) {
      if (state[i] != target[i]) {
        digitalWrite(stepPins[i], HIGH);
      }
    }

    delayMicroseconds(stepDelay);

    // step LOW for all required motors
    for (int i = 0; i < 6; i++) {
      if (state[i] != target[i]) {
        digitalWrite(stepPins[i], LOW);
      }
    }

    delayMicroseconds(stepDelay);
  }

  // update state after motion completes
  for (int i = 0; i < 6; i++) {
    if (state[i] != target[i]) {
      state[i] = target[i];
    }
  }
}


void moveMotor(int motorIndex, char direction, int steps)
{
  int dirSignal = (direction == 'u') ? HIGH : LOW;
  
  digitalWrite(dirPins[motorIndex], dirSignal);

  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPins[motorIndex], HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPins[motorIndex], LOW);
    delayMicroseconds(stepDelay);
  }
}


void resetAllPinsToDown()
{
  for (int i = 0; i < 6; i++) {
    if (state[i] == 'u') {
      moveMotor(i, 'd', stepsPerRevolution);
      state[i] = 'd';
    }
  }
}
