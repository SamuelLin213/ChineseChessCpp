#ifndef CHESSBOARD_SPOT
#define CHESSBOARD_SPOT

#include "enums.h"

class chessBoardSpot{
  public:
    void setColor(string color_);
    string getColor();
    void setOccupied(bool occupied_);
    bool getOccupied();
  private:
    bool occupied = false;
    colorEnum color;
    // ChessPiece piece; //uncomment when class for chess piece is created
}

#endif
