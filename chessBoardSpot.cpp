#include "chessBoardSpot.h"
#include <boost/algorithm/string.hpp>

class chessBoardSpot;

void chessBoardSpot::setColor(string color_)
{
  string colorLower = boost::algorithm::to_lower(color_)

  if(colorLower == "black")
  {
    this->color = BLACK;
  }
  else if(colorLower == "red")
  {
    this->color = RED;
  }
}
string chessBoardSpot::getColor()
{
  return this->color;
}
void chessBoardSpot::setOccupied(bool occupied_)
{
  this->occupied = occupied_;
}
bool chessBoardSpot::getOccupied()
{
  return this->occupied;
}
