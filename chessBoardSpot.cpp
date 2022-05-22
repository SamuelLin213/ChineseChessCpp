#include "chessBoardSpot.h"

class ChessBoardSpot;
using namespace std;

ChessBoardSpot::ChessBoardSpot(pieceTypeEnum newPieceType, bool newOccupied, colorEnum newColor, char newBoardChar)
{
      piece = newPieceType;
      occupied = newOccupied;
      color = newColor;
      boardChar = newBoardChar;
}

void ChessBoardSpot::setColor(string color_)
{
  transform(color_.begin(), color_.end(), color_.begin(),
    [](unsigned char c){ return std::tolower(c); });

  if(color_ == "black")
  {
    this->color = BLACK;
  }
  else if(color_ == "red")
  {
    this->color = RED;
  }
}
string ChessBoardSpot::getColor()
{
  // return this->color;
  return "";
}
void ChessBoardSpot::setOccupied(bool occupied_)
{
  this->occupied = occupied_;
}
bool ChessBoardSpot::getOccupied()
{
  return this->occupied;
}
