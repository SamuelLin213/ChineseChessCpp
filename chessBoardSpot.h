#ifndef CHESSBOARD_SPOT
#define CHESSBOARD_SPOT

#include <string>
#include "enums.h"
#include "validMove.h"
// #include "piece.h"

using namespace std;

class validMove;

class ChessBoardSpot{
  public:
    ChessBoardSpot() {};
    ChessBoardSpot(pieceTypeEnum piece_, colorEnum color_, char boardChar_, validMove* move_);

    void setData(pieceTypeEnum piece_, colorEnum color_,
    char boardChar_, validMove* move_);

    void setColor(colorEnum color_);
    colorEnum getColor();

    // void setOccupied(bool occupied_);
    // bool getOccupied();

    pieceTypeEnum getPiece();
    string getPieceStr();
    void setPiece(pieceTypeEnum piece_);

    char getChar();
    void setChar(char char_);

    void setMove(validMove* move_);
    validMove* getMove();

    void clear();
    void cpy(ChessBoardSpot cpy);

    ~ChessBoardSpot();
  private:
    pieceTypeEnum piece = EMPTY;
    // bool occupied = false;
    colorEnum color = NONE;
    char boardChar = '*';
    validMove* move = nullptr;
};

#endif
