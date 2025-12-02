#include "letter_dictionary.h"

const int dirPins[6]  = {13, 11, 9, 7, 5, 3};
const int stepPins[6] = {12, 10, 8, 6, 4, 2};
const int enPins[6] = {A0, A0, A5, A4, A3, A2};
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
    pinMode(enPins[i], OUTPUT);
    pinMode(stepPins[i], OUTPUT);
    digitalWrite(stepPins[i], LOW);
    digitalWrite(enPins[i], HIGH);
    digitalWrite(dirPins[i], LOW);
  }
  Serial.println("Commanding all motors up for calibration");
  char up[6] = {'u', 'u', 'u', 'u', 'u', 'u'};
  moveAllMotorsTogether(up, stepsPerRevolution);
  Serial.println("Commanding all down for calibration");
  char down[6] = {'d', 'd', 'd', 'd', 'd', 'd'};
  moveAllMotorsTogether(down, stepsPerRevolution);

  new_string.toUpperCase();
  new_string.toCharArray(charArray, new_string.length() + 1);
  Serial.print("Converting to braille the word: ");
  Serial.println(new_string);
 
      for (int i = 0; i < 6; i++) {
      Serial.print(state[i]);
    }

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
      char down[6] = {'d', 'd', 'd', 'd', 'd', 'd'};
      moveAllMotorsTogether(down, stepsPerRevolution);
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
    Serial.println();
    for (int i = 0; i < 6; i++) {
      digitalWrite(enPins[i], HIGH);
      Serial.print(state[i]);
    }
    Serial.println();
    letter++;
    
  }

}


void moveAllMotorsTogether(char target[6], int steps)
{
  int dirSignal;
  // set direction on each motor
  for (int i = 0; i < 6; i++) {
    if (state[i] != target[i]) {
      if (i == 4 || i == 3 || i == 1) {
        dirSignal = (target[i] == 'u') ? LOW : HIGH;
      } else {
        dirSignal = (target[i] == 'u') ? HIGH : LOW;
      }
      digitalWrite(enPins[i], LOW);
      Serial.println(i);
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
     for (int i = 0; i < 6; i++) {
      digitalWrite(enPins[i], HIGH);
    }
}
