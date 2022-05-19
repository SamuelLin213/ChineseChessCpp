#ifndef GENERAL_MOVE_H
#define GENERAL_MOVE_H
#include "ValidMoveStrategy.h"
#include "enums.h"
#include "GeneralMock_04.h"

class GeneralMove:public ValidMoveStrategy {

public:

bool validMove(int fromRow, int fromCol, int toRow, int toCol){

    //General cannot leave palace [3-5][0-2]
    if(((this->getColor() == RED && (toRow < 0 || toRow > 2)) ||
        (this->getColor() == BLACK && (toRow > 9 || toRow < 7))) ||
        (toCol < 3 || toCol > 5) ){
            return false;
    }

    //can only move one spot up/down or one spot left/right
    if(abs(fromRow - toRow) == 1 && abs(fromCol - toCol) == 0 ||
       abs(fromRow - toRow) == 0 && abs(fromCol - toCol) == 1){
    /*cannot be in the same column as the other general unless there
      is another piece between them*/
       for(int i = toRow; i < 10 ; i++){
           if(this[i][toCol]->getOccupied() == true){
               if(this[i][toCol]->getPiece() == GENERAL){
                   return false;
               }                  
               else{
                   return true;
               }
           }
       }
       return true;
    }
    return false;
}
};

#endif
