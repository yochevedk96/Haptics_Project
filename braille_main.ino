#include "letter_dictionary.h"

LetterDictionary dict;
String new_string = "hello";
char charArray[20];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  
  Serial.println("Please enter a word to convert to braille and hit ENTER");

  while (new_string.length() == 0) {
    if (Serial.available()) {}
      new_string = Serial.readStringUntil('\n');
      new_string.trim();
      new_string.toUpperCase();
      new_string.toCharArray(charArray, new_string.length() + 1);
      Serial.print("Converting to braille the word: ");
      Serial.println(new_string);
  }

}

void loop() {
  for (int i = 0; i < new_string.length(); i++)
  { 
    //TODO wait for button press
    
    char letter = charArray[i]
    int* values = dict.getValuesForLetter(letter);

    if (values != nullptr) {
      Serial.print("Commanding motors for the letter: ")
      Serial.println(letter);
     
    } else {
      Serial.print(" :( No value for character: ");
      Serial.println(letter);
    }
    
    //TODO command to motors
    
  }
  
  // put your main code here, to run repeatedly:

}
