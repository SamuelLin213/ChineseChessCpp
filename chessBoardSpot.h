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
    ChessBoardSpot();
    ChessBoardSpot(const ChessBoardSpot &cpyObj);
    ChessBoardSpot(pieceTypeEnum piece_, colorEnum color_, char boardChar_, validMove* move_);

    void setData(pieceTypeEnum piece_, colorEnum color_,
    char boardChar_, validMove* move_);

    void setColor(colorEnum color_);
    colorEnum getColor() const;

    // void setOccupied(bool occupied_);
    // bool getOccupied();

    pieceTypeEnum getPiece() const;
    string getPieceStr();
    void setPiece(pieceTypeEnum piece_);

    char getChar() const;
    void setChar(char char_);

    void setMove(validMove* move_);
    validMove* getMove() const;

    void clear();
    void cpy(ChessBoardSpot cpyObj);

    ~ChessBoardSpot();

    void print() {
        cout << "Piece: " << getPieceStr() << endl;
        cout << "Color: " << ((getColor() == 0) ? "red" : "black") << endl;
        cout << "Board Char: " << boardChar << endl;
        cout << "Move: " << ((move == nullptr) ? "null" : "not null") << endl << endl;
    }
  private:
    pieceTypeEnum piece = EMPTY;
    // bool occupied = false;
    colorEnum color = NONE;
    char boardChar = '*';
    validMove* move = nullptr;
};

#endif
