#ifndef ENUMS_H
#define ENUMS_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

#define RESET   "\033[0m"
#define BLACK_C  "\033[36m" // Changed black coloring to cyan for more visibility
#define RED_C     "\033[31m" // Red coloring
#define MAGENTA "\033[35m" // for numbers on side of board

enum pieceTypeEnum {
  GENERAL,
  ADVISOR,
  ELEPHANT,
  HORSE,
  CHARIOT,
  CANNON,
  SOLDIER,
  EMPTY
};

enum colorEnum {
  RED,
  BLACK,
  NONE
};

#endif
