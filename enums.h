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
  GENERAL,
  GUARD,
  ELEPHANT,
  HORSE,
  CHARIOT,
  CANNON,
  SOLDIER
};

enum colorEnum {
  RED,
  BLACK,
  NONE
};

// extern colorEnum color;
// extern colorEnum pieceColor;
// extern pieceTypeEnum pieceType;

#endif
