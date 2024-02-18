#include "converter.h"

const char Converter::MIN_POS_CHAR = 'a';

char Converter::intToLowerChar(const unsigned int in) {
  return MIN_POS_CHAR + in;
}

unsigned int Converter::lowerCharToInt(const char in) {
  return in - MIN_POS_CHAR;
}