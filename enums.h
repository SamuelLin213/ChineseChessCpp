#ifndef ENUMS_H
#define ENUMS_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

enum pieceTypeEnum {
  GENERAL = 0,
  ADVISOR = 1,
  ELEPHANT = 2,
  HORSE = 3,
  CHARIOT = 4,
  PAO = 5, //cannon
  SOLDIER = 6,
  NONE = 7, 
};

enum colorEnum {
  RED = 0,
  BLACK = 1,
  NONE = 3
};

// extern colorEnum color;
// extern colorEnum pieceColor;
// extern pieceTypeEnum pieceType;

#endif
