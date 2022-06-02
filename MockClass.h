#ifndef MOCKCLASSES_H
#define MOCKCLASSES_H

#include "validMove.h"

class GeneralMock_ChessBoardSpot {
public:
    enum colorEnum {
        RED,
        BLACK,
        NONE
    };

    colorEnum color;
    validMove* move;

    GeneralMock_ChessBoardSpot() {
        color = BLACK;
        move = new generalMove();
    }

    validMove* getMove() {
        return move;
    }


};

class AdvisorMock_ChessBoardSpot {
public:
    enum colorEnum {
        RED,
        BLACK,
        NONE
    };

    colorEnum color;
    validMove* move;

    AdvisorMock_ChessBoardSpot() {
        color = BLACK;
        move = new advisorMove();
    }

    validMove* getMove() {
        return move;
    }


};

class ElephantMock_ChessBoardSpot {
public:
    enum colorEnum {
        RED,
        BLACK,
        NONE
    };

    colorEnum color;
    validMove* move;

    ElephantMock_ChessBoardSpot() {
        color = BLACK;
        move = new elephantMove();
    }

    validMove* getMove() {
        return move;
    }


};

class SoldierMock_ChessBoardSpot {
public:
    enum colorEnum {
        RED,
        BLACK,
        NONE
    };

    colorEnum color;
    validMove* move;

    ElephantMock_ChessBoardSpot() {
        color = BLACK;
        move = new elephantMove();
    }

    validMove* getMove() {
        return move;
    }


};

#endif
