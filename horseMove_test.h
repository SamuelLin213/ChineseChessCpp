#ifndef HORSEMOVE_TEST
#define HORSEMOVE_TEST

#include "gtest/gtest.h"

#include "chessDisplay.h"
#include "game.h"
#include "chessBoardSpot.h"
#include "enums.h"
#include "validMove.h"
#include "MockClass.h"

//vector<int> kingCoor(4);
//bool spotOccupied[10][9]; // Stores status of each spot on board
//ChessBoardSpot** spots = new ChessBoardSpot*[10];
//initializeSpots(spots);
//defaultCoordinates(spots);

TEST(HorseTest, MoveDownRight) {
	HorseMock_ChessBoardSpot h;
	h.move->setCoors(2,0,4,1);

	bool occupied[10][9] =
    {   {0,0,1,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_TRUE(e.move->move(occupied, BLACK, king));
}

#endif
