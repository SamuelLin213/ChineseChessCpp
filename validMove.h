#ifndef VALIDMOVE_H
#define VALIDMOVE_H

#include "chessBoardSpot.h"
#include <cmath>
using namespace std;

class ChessBoardSpot;

// strategy class, other classes just need to inherit from this
class validMove {
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
    int newX = 0;
    int newY = 0;
    int currX = 0;
    int currY = 0;
};

class generalMove : public validMove {
public:
    generalMove() {}
    generalMove(int x, int y) {}
    ~generalMove() {}
    virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) {
	//General cannot leave palace [3-5][0-2]
	 if (((color == BLACK && (newY < 0 || newY > 2)) ||
            (color == RED && (newY > 9 || newY < 7))) ||
            (newX < 3 || newX > 5)) {
            return false;
         }
        //can only move one spot up/down or one spot left/right
        if (abs(currY - newY) == 1 && abs(currX - newX) == 0 ||
            abs(currY - newY) == 0 && abs(currX - newX) == 1) {
	    /*cannot be in the same column as the other general unless there
 	     is another piece between them*/
            if (color == BLACK) {
                for (int i = newY + 1; i < 10; i++) {
                    if (occupied[i][newX] == true) {
                        if (newX == king[2] && i == king[3]) {
                            return false;
                        }
                        else {
                            return true;
                        }
                    }
                }
		return true;
            }
            if (color == RED) {
                for (int i = newY - 1; i >= 0; i--) {
                    if (occupied[i][newX] == true) {
                        if (newX == king[0] && i == king[1]) {
                            return false;
                        }
                        else {
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

class advisorMove : public validMove {
public:
    advisorMove() {}
    advisorMove(int x, int y) {}
    ~advisorMove() {}
    virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) {
	//Advisor cannot leave Palace (RED[7-9]/BLACK[0-2])[3 -5]
        if (((color == BLACK && (newY < 0 || newY > 2)) ||
            (color == RED && (newY > 9 || newY < 7))) ||
            (newX < 3 || newX > 5)) {
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

class elephantMove : public validMove {
public:
    elephantMove() {}
    elephantMove(int x, int y) {}
    ~elephantMove() {}
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

class horseMove : public validMove {
public:
    horseMove() {}
    horseMove(int x, int y) {}
    ~horseMove() {}
    virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) { return true; }
};

class chariotMove : public validMove {
public:
    chariotMove() {}
    chariotMove(int x, int y) {}
    ~chariotMove() {}
    virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) { return true; }
};

class powMove : public validMove {
public:
    powMove() {}
    powMove(int x, int y) {}
    ~powMove() {}
    virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) { return true; }
};

class soldierMove : public validMove {
public:
    soldierMove() {}
    soldierMove(int x, int y) {}
    ~soldierMove() {}
    virtual bool move(bool occupied[][9], colorEnum color, vector<int> king) {
        vector<vector<int>> possible;
        if ((color == RED && currY < 6) || (color == BLACK && currY > 5))
        {
            vector<int> temp1 = { currX, currY + 1 };
            vector<int> temp2 = { currX - 1, currY };
            vector<int> temp3 = { currX + 1, currY };
            vector<int> temp4 = { newX, newY };

            cout << endl << temp1[0] << " " << temp1[1] << endl;
            cout << temp2[0] << " " << temp2[1] << endl;
            cout << temp3[0] << " " << temp3[1] << endl;
            cout << temp4[0] << " " << temp4[1] << endl << endl;

            possible.push_back(temp1);
            possible.push_back(temp2);
            possible.push_back(temp3);

            if (find(possible.begin(), possible.end(), temp4) != possible.end())
            {
                return true;
            }
            return false;
        }
        else {
            cout << "new: " << newX << " " << newY << endl;
            cout << "old: " << currX << " " << currY << endl;
            if (newX != currX || abs(newY - currY) != 1)
            {
                return false;
            }
            return true;
        }
	//return true;
    }
};

#endif
