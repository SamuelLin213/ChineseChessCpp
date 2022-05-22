#include "chessBoardSpot.h"

class ChessBoardSpot;
using namespace std;

ChessBoardSpot::ChessBoardSpot(pieceTypeEnum piece_, bool occupied_,
  colorEnum color_, char boardChar_, validMove* move_)
    :piece{piece_}, occupied{occupied}, color{color_}, boardChar{boardChar_}, move{move_}
{
}

void ChessBoardSpot::setColor(colorEnum color_)
{
  // transform(color_.begin(), color_.end(), color_.begin(),
  //   [](unsigned char c){ return std::tolower(c); });
  //
  // if(color_ == "black")
  // {
  //   this->color = BLACK;
  // }
  // else if(color_ == "red")
  // {
  //   this->color = RED;
  // }
  this->color = color_;
}
colorEnum ChessBoardSpot::getColor()
{
  // return this->color;
  return this->color;
}
void ChessBoardSpot::setOccupied(bool occupied_)
{
  this->occupied = occupied_;
}
bool ChessBoardSpot::getOccupied()
{
  return this->occupied;
}

pieceTypeEnum ChessBoardSpot::getPiece()
{
  return this->piece;
}
void ChessBoardSpot::setPiece(pieceTypeEnum piece_)
{
  this->piece = piece_;
}

char ChessBoardSpot::getChar()
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
bool ChessBoardSpot::movePiece()
{
  return this->move;
}

ChessBoardSpot::~ChessBoardSpot()
{
  delete move;
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

void ChessBoardSpot::setData(pieceTypeEnum piece_, bool occupied_, colorEnum color_,
char boardChar_, validMove* move_)
{
  piece = piece_;
  occupied = occupied_;
  color = color_;
  boardChar = boardChar_;
  move = move_;
}
