#ifndef ADVISOR_MOVE_H
#define ADVISOR_MOVE_H
#include "ValidMoveStrategy.h"

class AdvisorMove:public ValidMoveStrategy {

public:
    bool validMove(int fromRow, int from Col, int toRow, int toCol){

        //Advisor cannot leave Palace (Black[7-9]/Red[0-2])[3 -5]
        if(((this->getColor() == BLACK && (toRow < 0 || toRow > 2)) ||
            (this->getColor() == RED && (toRow > 9 || toRow < 7))) ||
            (toCol < 3 || to Col > 5)){
              return false;
        }
    
        //can only move diagonally
        if((abs(fromRow - toRow) != 1 || abs(fromCol - toCol) != 1)){
                return false;
        }  
        return true;
};

#endif
