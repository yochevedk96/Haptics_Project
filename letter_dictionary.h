#include <Arduino.h>

struct LetterMapping {
  char letter;
  char values[6];
};

class LetterDictionary {
  public:
    LetterDictionary();
    char* getValuesForLetter(char input);
    //char* getValuesForDigit(int digit);
  private:
    static const int NUM_LETTERS = 35;
    LetterMapping dictionary[NUM_LETTERS];
    void initDictionary();
  };
