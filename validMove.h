#ifndef VALIDMOVE_H
#define VALIDMOVE_H

#include "ChessBoardSpot.h"
#include <cmath>
using namespace std;

class ChessBoardSpot;

// strategy class, other classes just need to inherit from this
class validMove
{
  public:
    validMove() {}
    validMove(int x, int y) {}
    virtual void setCoors(int currX_, int currY_, int newX_, int newY_)
    {
      newX = newX_;
      newY = newY_;
      currX = currX_;
      currY = currY_;
    }
    ~validMove() {}
    virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) = 0;
  protected:
    int newX;
    int newY;
    int currX;
    int currY;
};

// other pieces inherit from validMove
class generalMove: public validMove 
{
public:
  generalMove() {}
  generalMove(int x, int y) {}
  ~generalMove() {}
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) 
  {
      vector<vector<int> > possible;
      ChessBoardSpot** spots = new ChessBoardSpot*[BOARD_HEIGHT];
      ChessBoardSpot temp = spots[currX][currY];

      if(temp.getColor() != spots[currX][currY-1].getColor())
      {
          vector<int> ValidMove1 { currX, currY-1};
          possible.push_back(ValidMove1);
      }
      else if(temp.getColor() != spots[currX][currY+1].getColor())
      {
          vector<int> ValidMove2 { currX, currY+1};
          possible.push_back(ValidMove2);
      }
      else if(temp.getColor() != spots[currX-1][currY].getColor())
      {
          vector<int> ValidMove3 { currX-1, currY};
          possible.push_back(ValidMove3);
      }
      else if(temp.getColor() != spots[currX+1][currY].getColor())
      {
          vector<int> ValidMove4 { currX+1, currY};
          possible.push_back(ValidMove4);

      }

      vector<int> newLocation {newX, newY};

      if(find(possible.begin(), possible.end(), newLocation) != possible.end()) // we search through the fector possible
      {
        return true;
      }
      return false;

      
      
  }
};

class advisorMove: public validMove 
{
public:
  advisorMove() {}
  advisorMove(int x, int y) {}
  ~advisorMove() {}
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) { return true; }
};

class elephantMove: public validMove 
{
public:
  elephantMove() {}
  elephantMove(int x, int y) {}
  ~elephantMove() {}
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) { return true; }
};

class horseMove: public validMove 
{
public:
  horseMove() {}
  horseMove(int x, int y) {}
  ~horseMove() {}
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) { return true; }
};

class chariotMove: public validMove 
{
public:
  chariotMove() {}
  chariotMove(int x, int y) {}
  ~chariotMove() {}
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) { return true; }
};

class powMove: public validMove 
{
public:
  powMove() {}
  powMove(int x, int y) {}
  ~powMove() {}
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) { return true; }
};

class soldierMove: public validMove
{
public:
  soldierMove() {}
  soldierMove(int x, int y) {}
  ~soldierMove() {}
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) 
  {
    vector<vector<int> > possible;

    if( (color == RED && currY < 6) || (color == BLACK && currY > 5))
    {

      vector<int> temp1;
      if(color == RED) // only valid move is do move down
      {
        temp1 = { currX, currY - 1};
      }
      else if(color == BLACK) // only valid move is to move up
      {
        temp1 = {currX, currY + 1};
      }
      vector<int> temp2 {currX - 1, currY};
      vector<int> temp3 {currX + 1, currY};
      vector<int> temp4 {newX, newY};

      // cout << endl << temp1[0] << " " << temp1[1] << endl;
      // cout << temp2[0] << " " << temp2[1] << endl;
      // cout << temp3[0] << " " << temp3[1] << endl;
      // cout << temp4[0] << " " << temp4[1] << endl << endl;

      possible.push_back(temp1);
      possible.push_back(temp2);
      possible.push_back(temp3);

      if(find(possible.begin(), possible.end(), temp4) != possible.end()) // we search through the fector possible
      {
        return true;
      }
      return false;
    }
    else {
      cout << "new: " << newX << " " << newY << endl;
      cout << "old: " << currX << " " << currY << endl;
      if(newX != currX)
      {
        return false;
      }
      if(color == RED && newY != currY - 1)
        return false;
      if(color == BLACK && newY != currY + 1)
        return false;
      return true;
    }
    // return true;
  }
};


#endif
