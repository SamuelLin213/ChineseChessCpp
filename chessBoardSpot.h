#ifndef CHESSBOARD_SPOT
#define CHESSBOARD_SPOT

#include <string>
#include "enums.h"
// #include "piece.h"

using namespace std;

class ChessBoardSpot
{
  public:
    ChessBoardSpot() {};
    ChessBoardSpot(pieceTypeEnum piece, bool occupied, colorEnum color, char boardChar); 
    void setColor(string color_);
    string getColor();

    void setOccupied(bool occupied_);
    bool getOccupied();

    string getPiece();
    void setPiece(string piece_);

    char getChar();
    void setChar(char char_);
  private:
    pieceTypeEnum piece;
    bool occupied = false;
    colorEnum color = NONE;
    char boardChar = '*';
};

#endif
