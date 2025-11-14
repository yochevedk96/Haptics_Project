#include "letter_dictionary.h"

LetterDictionary::LetterDictionary() {
  initDictionary();
}

void LetterDictionary::initDictionary() {
  
  dictionary[0] = { 'A', {1, 0, 0, 0, 0, 0} };
  dictionary[1] = { 'B', {1, 0, 1, 0, 0, 0} };
  dictionary[2] = { 'C', {1, 1, 0, 0, 0, 0} };
  dictionary[3] = { 'D', {1, 1, 0, 1, 0, 0} };
  dictionary[4] = { 'E', {1, 0, 0, 1, 0, 0} };
  dictionary[5] = { 'F', {1, 1, 1, 0, 0, 0} };
  dictionary[6] = { 'G', {1, 1, 1, 1, 0, 0} };
  dictionary[7] = { 'H', {1, 0, 1, 1, 0, 0} };
  dictionary[8] = { 'I', {0, 1, 1, 0, 0, 0} };
  dictionary[9] = { 'J', {0, 1, 1, 1, 0, 0} };
  dictionary[10] = { 'K', {1, 0, 0, 0, 1, 0} };
  dictionary[11] = { 'L', {1, 0, 1, 0, 1, 0} };
  dictionary[12] = { 'M', {1, 1, 0, 0, 1, 0} };
  dictionary[13] = { 'N', {1, 1, 0, 1, 1, 0} };
  dictionary[14] = { 'O', {1, 0, 0, 1, 1, 0} };
  dictionary[15] = { 'P', {1, 1, 1, 0, 1, 0} };
  dictionary[16] = { 'Q', {1, 1, 1, 1, 1, 0} };
  dictionary[17] = { 'R', {1, 0, 1, 1, 1, 0} };
  dictionary[18] = { 'S', {0, 1, 1, 0, 1, 0} };
  dictionary[19] = { 'T', {0, 1, 1, 1, 1, 0} };
  dictionary[20] = { 'U', {1, 0, 0, 0, 0, 1} };
  dictionary[21] = { 'V', {1, 0, 1, 0, 1, 1} };
  dictionary[22] = { 'W', {0, 1, 1, 1, 0, 1} };
  dictionary[23] = { 'X', {1, 1, 0, 0, 1, 1} };
  dictionary[24] = { 'Y', {1, 1, 0, 1, 1, 1} };
  dictionary[25] = { 'Z', {1, 0, 0, 1, 1, 1} };
  dictionary[26] = { ' ', {0, 0, 0, 0, 0, 0} };
  dictionary[27] = [ '#', {0, 1, 0, 1, 1, 1} };
  
}

int* LetterDictionary::getValuesForLetter(char input) {
  for (int i = 0; i < NUM_LETTERS; i++) {
    if (dictionary[i].letter == input) {
      return dictionary[i].values;
    }
  }
  return nullptr;
}

int* LetterDictionary::getValuesForDigit(int digit) {
    if (digit == 0) return getValuesForLetter('J');
    if (digit >= 1 && digit <= 9) return getValuesForLetter('A' + (digit - 1));
    return nullptr;
}
