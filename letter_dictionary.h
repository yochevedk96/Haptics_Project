#include <Arduino.h>

struct LetterMapping {
  char letter;
  int values[6];
};

class LetterDictionary {
  public:
    LetterDictionary();
    int* getValuesForLetter(char input);
    int* getValuesForDigit(int digit);
  private:
    static const int NUM_LETTERS = 27;
    LetterMapping dictionary[NUM_LETTERS];
    void initDictionary();
  };
