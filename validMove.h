#ifndef VALIDMOVE_H
#define VALIDMOVE_H

#include "ChessBoardSpot.h"

class ChessBoardSpot;

// strategy class, other classes just need to inherit from this
class validMove{
  public:
    validMove() {}
    validMove(int x, int y) {}
    ~validMove() {}
    virtual bool move(ChessBoardSpot** spots) = 0;
  private:
    int newX;
    int newY;
};

// other pieces inherit from validMove
class generalMove: public validMove {
public:
  generalMove() {}
  generalMove(int x, int y) {}
  ~generalMove() {}
  virtual bool move(ChessBoardSpot** spots) { return true; }
};

class advisorMove: public validMove {
public:
  advisorMove() {}
  advisorMove(int x, int y) {}
  ~advisorMove() {}
  virtual bool move(ChessBoardSpot** spots) { return true; }
};

class elephantMove: public validMove {
public:
  elephantMove() {}
  elephantMove(int x, int y) {}
  ~elephantMove() {}
  virtual bool move(ChessBoardSpot** spots) { return true; }
};

class horseMove: public validMove {
public:
  horseMove() {}
  horseMove(int x, int y) {}
  ~horseMove() {}
  virtual bool move(ChessBoardSpot** spots) { return true; }
};

class chariotMove: public validMove {
public:
  chariotMove() {}
  chariotMove(int x, int y) {}
  ~chariotMove() {}
  virtual bool move(ChessBoardSpot** spots) { return true; }
};

class powMove: public validMove {
public:
  powMove() {}
  powMove(int x, int y) {}
  ~powMove() {}
  virtual bool move(ChessBoardSpot** spots) { return true; }
};

class soldierMove: public validMove {
public:
  soldierMove() {}
  soldierMove(int x, int y) {}
  ~soldierMove() {}
  virtual bool move(ChessBoardSpot** spots) { return true; }
};


#endif
