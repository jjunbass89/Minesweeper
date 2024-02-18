#ifndef converter_H
#define converter_H

class Converter {
 public:
  static char intToLowerChar(const unsigned int in);
  static unsigned int lowerCharToInt(const char in);

 public:
  static const char MIN_POS_CHAR;
};

#endif
