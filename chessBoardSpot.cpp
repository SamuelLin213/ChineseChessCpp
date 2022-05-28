#include "chessBoardSpot.h"

class ChessBoardSpot;
using namespace std;

ChessBoardSpot::ChessBoardSpot(pieceTypeEnum piece_, colorEnum color_, char boardChar_, validMove* move_)
    :piece{piece_}, color{color_}, boardChar{boardChar_}, move{move_}
{
}

ChessBoardSpot::ChessBoardSpot()
{
  move = new validMove();
  move = nullptr;
  piece = EMPTY;
  color = NONE;
  boardChar = '*';
}

void ChessBoardSpot::setColor(colorEnum color_)
{
  this->color = color_;
}
colorEnum ChessBoardSpot::getColor() const
{
  return this->color;
}

pieceTypeEnum ChessBoardSpot::getPiece() const
{
  return this->piece;
}
void ChessBoardSpot::setPiece(pieceTypeEnum piece_)
{
  this->piece = piece_;
}

char ChessBoardSpot::getChar() const
{
  return this->boardChar;
}
void ChessBoardSpot::setChar(char char_)
{
  this->boardChar = char_;
}

void ChessBoardSpot::setMove(validMove* move_)
{
  this->move = move_;
}
validMove* ChessBoardSpot::getMove() const
{
  return this->move;
}

ChessBoardSpot::~ChessBoardSpot()
{
  delete move;
}

void ChessBoardSpot::clear()
{
  this->piece = EMPTY;
  this->color = NONE;
  this->boardChar = '*';
  this->move = nullptr;
}

// need to use this to copy over data; do NOT use = to copy objects
void ChessBoardSpot::cpy(ChessBoardSpot cpy)
{
  this->clear();

  delete this->move;

  this->piece = cpy.piece;
  this->color = cpy.color;
  this->boardChar = cpy.boardChar;
  this->move = new validMove(*cpy.move);
}

string ChessBoardSpot::getPieceStr()
{
  switch(this->piece)
  {
    case GENERAL:
    {
      return "general";
      break;
    }
    case ADVISOR:
    {
      return "advisor";
      break;
    }
    case ELEPHANT:
    {
      return "elephant";
      break;
    }
    case HORSE:
    {
      return "horse";
      break;
    }
    case CHARIOT:
    {
      return "chariot";
      break;
    }
    case CANNON:
    {
      return "cannon";
      break;
    }
    case SOLDIER:
    {
      return "soldier";
      break;
    }
  }
}

ChessBoardSpot::ChessBoardSpot(const ChessBoardSpot &cpyObj)
{
  this->clear();
  piece = cpyObj.getPiece();
  color = cpyObj.getColor();
  boardChar = cpyObj.getChar();
  delete this->move;
  //this->move->cpy(*cpyObj.getMove());
  this->move = new validMove(*cpyObj.getMove());
}

void ChessBoardSpot::setData(pieceTypeEnum piece_, colorEnum color_,
char boardChar_, validMove* move_)
{
  piece = piece_;
  color = color_;
  boardChar = boardChar_;
  move = move_;
}
