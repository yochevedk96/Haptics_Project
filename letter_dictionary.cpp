#include "letter_dictionary.h"

LetterDictionary::LetterDictionary() {
  initDictionary();
}

void LetterDictionary::initDictionary() {
  
  dictionary[0] = { 'A', {'u', 'd', 'd', 'd', 'd', 'd'} };
  dictionary[1] = { 'B', {'u', 'd', 'u', 'd', 'd', 'd'} };
  dictionary[2] = { 'C', {'u', 'u', 'd', 'd', 'd', 'd'} };
  dictionary[3] = { 'D', {'u', 'u', 'd', 'u', 'd', 'd'} };
  dictionary[4] = { 'E', {'u', 'd', 'd', 'u', 'd', 'd'} };
  dictionary[5] = { 'F', {'u', 'u', 'u', 'd', 'd', 'd'} };
  dictionary[6] = { 'G', {'u', 'u', 'u', 'u', 'd', 'd'} };
  dictionary[7] = { 'H', {'u', 'd', 'u', 'u', 'd', 'd'} };
  dictionary[8] = { 'I', {'d', 'u', 'u', 'd', 'd', 'd'} };
  dictionary[9] = { 'J', {'d', 'u', 'u', 'u', 'd', 'd'} };
  dictionary[10] = { 'K', {'u', 'd', 'd', 'd', 'u', 'd'} };
  dictionary[11] = { 'L', {'u', 'd', 'u', 'd', 'u', 'd'} };
  dictionary[12] = { 'M', {'u', 'u', 'd', 'd', 'u', 'd'} };
  dictionary[13] = { 'N', {'u', 'u', 'd', 'u', 'u', 'd'} };
  dictionary[14] = { 'O', {'u', 'd', 'd', 'u', 'u', 'd'} };
  dictionary[15] = { 'P', {'u', 'u', 'u', 'd', 'u', 'd'} };
  dictionary[16] = { 'Q', {'u', 'u', 'u', 'u', 'u', 'd'} };
  dictionary[17] = { 'R', {'u', 'd', 'u', 'u', 'u', 'd'} };
  dictionary[18] = { 'S', {'d', 'u', 'u', 'd', 'u', 'd'} };
  dictionary[19] = { 'T', {'d', 'u', 'u', 'u', 'u', 'd'} };
  dictionary[20] = { 'U', {'u', 'd', 'd', 'd', 'd', 'u'} };
  dictionary[21] = { 'V', {'u', 'd', 'u', 'd', 'u', 'u'} };
  dictionary[22] = { 'W', {'d', 'u', 'u', 'u', 'd', 'u'} };
  dictionary[23] = { 'X', {'u', 'u', 'd', 'd', 'u', 'u'} };
  dictionary[24] = { 'Y', {'u', 'u', 'd', 'u', 'u', 'u'} };
  dictionary[25] = { 'Z', {'u', 'd', 'd', 'u', 'u', 'u'} };
  dictionary[26] = { ' ', {'d', 'd', 'd', 'd', 'd', 'd'} };
  dictionary[27] = { ',', {'d', 'd', 'u', 'd', 'd', 'd'} };
  dictionary[28] = { '.', {'d', 'd', 'u', 'u', 'd', 'u'} };
  dictionary[29] = { '?', {'d', 'd', 'u', 'd', 'u', 'u'} };
  dictionary[30] = { '!', {'d', 'd', 'u', 'u', 'u', 'd'} };
  dictionary[31] = { ';', {'d', 'd', 'u', 'd', 'u', 'd'} };
  dictionary[32] = { ':', {'d', 'd', 'u', 'u', 'd', 'd'} };
  dictionary[33] = [ '#', {'d', 'u', 'd', 'u', 'u', 'u'} };
  
}

char* LetterDictionary::getValuesForLetter(char input) {
  for (int i = 0; i < NUM_LETTERS; i++) {
    if (dictionary[i].letter == input) {
      return dictionary[i].values;
    }
  }
  return nullptr;
}

/*char* LetterDictionary::getValuesForDigit(int digit) {
    if (digit == 0) return getValuesForLetter('J');
    if (digit >= 1 && digit <= 9) return getValuesForLetter('A' + (digit - 1));
    return nullptr;
}*/
