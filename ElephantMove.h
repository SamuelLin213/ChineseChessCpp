#ifndef ELEPHANT_MOVE_H
#define ELEPHANT_MOVE_H
#include "ValidMoveStrategy.h"

class ElephantMove:public ValidMoveStrategy {

public:

    bool validMove(int fromRow, int fromCol, int toRow, int toCol){
        int  midx = (toCol - from Col)/2;
        int midy = (toRow - from Row)/2;

        //elephant cannot cross river Red[0-4]/Black[5-9]
        if((this->getColor() == BLACK && toRow > 4) || 
           (this->getColor() == RED && toRow < 5)){
               return false;
        }
        //can only move two spaces diagonally with an empty space in the middle
        if((abs(fromRow - toRow) != 2 || abs(fromCol - toCol) != 2) ||
           (this[midx][midy]->getOccupied() != false)){
               return false;
        }
        return true;
    }
};

#endif
