#ifndef HORSEMOVE_TEST
#define HORSEMOVE_TEST

#include "gtest/gtest.h"

#include "validMove.h"
#include "MockClass.h"


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
    EXPECT_TRUE(h.move->move(occupied, BLACK, king));
}

TEST(HorseTest, MoveUpRight) {
	HorseMock_ChessBoardSpot h;
	h.move->setCoors(1,2,2,4);

	bool occupied[10][9] =
    {   {0,0,1,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_TRUE(h.move->move(occupied, BLACK, king));
}

TEST(HorseTest, MoveDownLeft) {
	HorseMock_ChessBoardSpot h;
	h.move->setCoors(4,4,3,2);

	bool occupied[10][9] =
    {   {0,0,1,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_TRUE(h.move->move(occupied, BLACK, king));
}

TEST(HorseTest, MoveUpLeft) {
	HorseMock_ChessBoardSpot h;
	h.move->setCoors(4,4,3,6);

	bool occupied[10][9] =
    {   {0,0,1,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_TRUE(h.move->move(occupied, BLACK, king));
}


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
    EXPECT_TRUE(h.move->move(occupied, BLACK, king));
}

TEST(HorseTest, BlockMovement) {
	HorseMock_ChessBoardSpot up;
	HorseMock_ChessBoardSpot down;
	HorseMock_ChessBoardSpot left;
	HorseMock_ChessBoardSpot right;

	up.move->setCoors(4,4,3,2);
	down.move->setCoors(4,4,5,6);
	left.move->setCoors(4,4,3,6);
	right.move->setCoors(4,4,6,5);

	bool occupied[10][9] =
    {   {0,0,1,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,1,1,1,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_FALSE(up.move->move(occupied, BLACK, king));
    EXPECT_FALSE(down.move->move(occupied, BLACK, king));
    EXPECT_FALSE(right.move->move(occupied, BLACK, king));
    EXPECT_FALSE(left.move->move(occupied, BLACK, king));
}

TEST(HorseTest, CaptureTest) {
	HorseMock_ChessBoardSpot h;
	h.move->setCoors(4,4,5,6);

	bool occupied[10][9] =
    {   {0,0,1,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_TRUE(h.move->move(occupied, BLACK, king));
}

#endif
