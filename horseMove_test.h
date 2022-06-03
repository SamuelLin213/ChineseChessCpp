#ifndef HORSEMOVE_TEST
#define HORSEMOVE_TEST

#include "gtest/gtest.h"

#include "chessDisplay.h"
#include "game.h"
#include "chessBoardSpot.h"
#include "enums.h"
#include "validMove.h"

vector<int> king(4);
bool spot[10][9]; // Stores status of each spot on board
ChessBoardSpot** spots = new ChessBoardSpot*[10];
initializeSpots(spots);
defaultCoordinates(spots);

TEST(RedHorseTest, MoveUpLeft)
{
  spots[9][1].getMove()->setCoors(1, 9, 2, 7);
  EXPECT_TRUE(spots[9][1].getMove()->move(spot, NONE, king));
}

#endif
