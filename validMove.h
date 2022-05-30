#ifndef VALIDMOVE_H
#define VALIDMOVE_H

#include "ChessBoardSpot.h"
#include <cmath>
using namespace std;

class ChessBoardSpot;

// strategy class, other classes just need to inherit from this
class validMove{
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
    virtual void cpy(const validMove& cpyObj) {};
    validMove(const validMove& other)
    {
      this->newX = other.newX;
      this->newY = other.newY;
      this->currX = other.currX;
      this->currY = other.currY;
    }
    ~validMove() {}
    virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) { return false; };
  protected:
    int newX;
    int newY;
    int currX;
    int currY;
};

// other pieces inherit from validMove
class generalMove: public validMove {
public:
  generalMove() {}
  generalMove(int x, int y) {}
  generalMove(const generalMove& other)
  {
    this->newX = other.newX;
    this->newY = other.newY;
    this->currX = other.currX;
    this->currY = other.currY;
  }
  ~generalMove() {}
  void cpy(const generalMove& objCpy)
  {
    this->newX = objCpy.newX;
    this->newY = objCpy.newY;
    this->currY = objCpy.currY;
    this->currX = objCpy.currX;
  }
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) {
    cout << endl << "General move called!" << endl;

    //General cannot leave palace [3-5][0-2]
	 if ( (color == BLACK && (newY < 0 || newY > 2)) ||
            (color == RED && (newY > 9 || newY < 7)) ||
            (newX < 3 || newX > 5))
   {
     return false;
   }
    //can only move one spot up/down or one spot left/right
    if (abs(currY - newY) == 1 && abs(currX - newX) == 0 ||
      abs(currY - newY) == 0 && abs(currX - newX) == 1) {
	    /*cannot be in the same column as the other general unless there
 	     is another piece between them*/
      if (color == BLACK) {
          for (int i = newY + 1; i < 10; i++)
          {
              if (occupied[i][newX] == true)
              {
                  if (newX == king[2] && i == king[3])
                  {
                      return false;
                  }
                  else {
                      return true;
                  }
              }
           }
	         return true;
       }
      if (color == RED)
      {
          for (int i = newY - 1; i >= 0; i--)
          {
              if (occupied[i][newX] == true)
              {
                  if (newX == king[0] && i == king[1])
                  {
                      return false;
                  }
                  else
                  {
                      return true;
                  }
              }
          }
          return true;
      }
    }
    return false;
  }
};

class advisorMove: public validMove {
public:
  advisorMove() {}
  advisorMove(int x, int y) {}
  advisorMove(const advisorMove& other)
  {
    this->newX = other.newX;
    this->newY = other.newY;
    this->currX = other.currX;
    this->currY = other.currY;
  }
  ~advisorMove() {}
  void cpy(const advisorMove& objCpy)
  {
    this->newX = objCpy.newX;
    this->newY = objCpy.newY;
    this->currY = objCpy.currY;
    this->currX = objCpy.currX;
  }
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) {
    //Advisor cannot leave Palace (RED[7-9]/BLACK[0-2])[3 -5]
        if ( (color == BLACK && (newY < 0 || newY > 2)) ||
            (color == RED && (newY > 9 || newY < 7)) ||
            (newX < 3 || newX > 5) ) {
            return false;
        }
        //can only move diagonally one space
        if ((abs(currY - newY) == 1 && abs(currX - newX) == 1)) {
            return true;
        }
      	else{
      	    return false;
      	}
    }
};

class elephantMove: public validMove {
public:
  elephantMove() {}
  elephantMove(int x, int y) {}
  elephantMove(const elephantMove& other)
  {
    this->newX = other.newX;
    this->newY = other.newY;
    this->currX = other.currX;
    this->currY = other.currY;
  }
  ~elephantMove() {}
  void cpy(const elephantMove& objCpy)
  {
    this->newX = objCpy.newX;
    this->newY = objCpy.newY;
    this->currY = objCpy.currY;
    this->currX = objCpy.currX;
  }
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) {
    //elephant cannot cross river Red[0-4]/Black[5-9]
        if ((color == BLACK && newY > 4) ||
            (color == RED && newY < 5)) {
            return false;
        }
        //can only move two spaces diagonally with an empty space in the middle
        int  midx = (newX - currX) / 2;
        int midy = (newY - currY) / 2;
        if ((abs(currY - newY) != 2 || abs(currX - newX) != 2) ||
            (occupied[currY + midy][currX + midx] != false)) {
            return false;
        }
        return true;
  }
};

class horseMove: public validMove {
public:
  horseMove() {}
  horseMove(int x, int y) {}
  horseMove(const horseMove& other)
  {
    this->newX = other.newX;
    this->newY = other.newY;
    this->currX = other.currX;
    this->currY = other.currY;
  }
  ~horseMove() {}
  void cpy(const horseMove& objCpy)
  {
    this->newX = objCpy.newX;
    this->newY = objCpy.newY;
    this->currY = objCpy.currY;
    this->currX = objCpy.currX;
  }
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) { return true; }
};

class chariotMove : public validMove {
public:
    chariotMove() {}
    chariotMove(int x, int y) {}
    ~chariotMove() {}
    chariotMove(const chariotMove& other)
    {
      this->newX = other.newX;
      this->newY = other.newY;
      this->currX = other.currX;
      this->currY = other.currY;
    }
    void cpy(const chariotMove& objCpy)
    {
      this->newX = objCpy.newX;
      this->newY = objCpy.newY;
      this->currY = objCpy.currY;
      this->currX = objCpy.currX;
    }
    virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) {
    	if (currX > newX) { // moving left
        if(currY != newY)
        {
          return false;
        }
    		for (int i = currX - 1; i > newX; i--) {
    			if (occupied[currY][i] == true) { return false;}
    		}
        return true;
    	}
    	else if (currX < newX) { //moving right
        if(currY != newY)
        {
          return false;
        }
    		for (int i = currX + 1; i < newX; i++) {
    			if (occupied[i][currY] == true) { return false;}
    		}
        return true;
    	}
    	else if (currY > newY) { // moving up board(from black's POV)
        if(currX != newX)
        {
          return false;
        }
    		for (int i = currY - 1; i > newY; i--) {
    			if (occupied[i][currX] == true) { return false;}
    		}
        return true;
    	}
    	else if (currY < newY ) { //moving down board(from black's POV)
        if(currX != newX)
        {
          return false;
        }
    		for (int i = currY + 1; i < newY; i++) {
    			if (occupied[i][currX] == true) { return false;}
    		}
        return true;
    	}
      return false;
   }
};

class powMove: public validMove {
public:
  powMove() {}
  powMove(int x, int y) {}
  ~powMove() {}
  powMove(const powMove& other)
  {
    this->newX = other.newX;
    this->newY = other.newY;
    this->currX = other.currX;
    this->currY = other.currY;
  }
  void cpy(const powMove& objCpy)
  {
    this->newX = objCpy.newX;
    this->newY = objCpy.newY;
    this->currY = objCpy.currY;
    this->currX = objCpy.currX;
  }
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) { return true; }
};

class soldierMove: public validMove{
public:
  soldierMove() {}
  soldierMove(const soldierMove& other)
  {
    this->newX = other.newX;
    this->newY = other.newY;
    this->currX = other.currX;
    this->currY = other.currY;
  }
  void cpy(const soldierMove& objCpy) //maybe change to validMove pointer
  {
    this->newX = objCpy.newX;
    this->newY = objCpy.newY;
    this->currY = objCpy.currY;
    this->currX = objCpy.currX;
  }
  soldierMove(int x, int y) {}
  ~soldierMove() {}
  virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) {
    vector<vector<int>> possible;
    // cout << endl << "curr: " << currX << " " << currY << endl;
    // cout << "new: " << newX << " " << newY << endl;
    // cin.get();
    // cin.ignore();
    cout << "Calling Move for soldier!" << endl;
    cin.ignore();
    cin.get();

    if( (color == RED && currY < 5) || (color == BLACK && currY > 4))
    {
      vector<int> temp1;
      if(color == RED)
      {
        temp1 = {currX, currY - 1};
      }
      else if(color == BLACK)
      {
        temp1  = {currX, currY + 1};
      }
      vector<int> temp2 = {currX - 1, currY};
      vector<int> temp3 = {currX + 1, currY};
      vector<int> temp4 = {newX, newY};

      // cout << endl << temp1[0] << " " << temp1[1] << endl;
      // cout << temp2[0] << " " << temp2[1] << endl;
      // cout << temp3[0] << " " << temp3[1] << endl;
      // cout << temp4[0] << " " << temp4[1] << endl << endl;

      possible.push_back(temp1);
      possible.push_back(temp2);
      possible.push_back(temp3);

      if(find(possible.begin(), possible.end(), temp4) != possible.end())
      {
        return true;
      }
      return false;
    }
    else {
      // cout << "curr: " << currX << " " << currY << endl;
      // cout << "new: " << newX << " " << newY << endl;
      if(newX != currX)
      {
        return false;
      }
      if(color == RED && newY != currY - 1)
      {
        return false;
      }
      if(color == BLACK && newY != currY + 1)
      {
        return false;
      }
      return true;
    }
    // return true;
  }
};


#endif
