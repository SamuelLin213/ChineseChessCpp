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
        move = new elephantMove();
    }

    validMove* getMove() {
        return move;
    }
};

class PowMock_ChessBoardSpot {
public:
    enum colorEnum {
        RED,
        BLACK,
        NONE
    };

    colorEnum color;
    validMove* move;

    PowMock_ChessBoardSpot() {
        move = new powMove();
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

    SoldierMock_ChessBoardSpot() {
        color = BLACK;
        move = new soldierMove();
    }

    validMove* getMove() {
        return move;
    }
};
#endif
