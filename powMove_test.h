#ifndef POWMOVE_TEST_HPP
#define POWMOVE_TEST_HPP

#include "gtest/gtest.h"
#include "validMove.h"
#include "MockClass.h"

TEST(BPow, AllEmpty) {
    PowMock_ChessBoardSpot up;
    PowMock_ChessBoardSpot dwn;
    PowMock_ChessBoardSpot right;
    PowMock_ChessBoardSpot left;

    up.move->setCoors(4, 4, 4, 0);
    dwn.move->setCoors(4, 4, 4, 9);
    right.move->setCoors(4, 4, 0, 4);
    left.move->setCoors(4, 4, 8, 4);

    bool occupied[10][9] =
    {   {0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };

    vector<int> king = { 3,0,5,9 };
    EXPECT_TRUE(up.move->move(occupied, BLACK, king));
    EXPECT_TRUE(dwn.move->move(occupied, BLACK, king));
    EXPECT_TRUE(right.move->move(occupied, BLACK, king));
    EXPECT_TRUE(left.move->move(occupied, BLACK, king));
}

TEST(BPow, CaptureCorrect) {
    PowMock_ChessBoardSpot up;
    PowMock_ChessBoardSpot dwn;
    PowMock_ChessBoardSpot right;
    PowMock_ChessBoardSpot left;

    up.move->setCoors(4, 4, 4, 0);
    dwn.move->setCoors(4, 4, 4, 9);
    right.move->setCoors(4, 4, 0, 4);
    left.move->setCoors(4, 4, 8, 4);

    bool occupied[10][9] =
    {   {0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {1,1,0,0,1,0,1,0,1},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0},
    };

    vector<int> king = { 3,0,5,9 };
    EXPECT_TRUE(up.move->move(occupied, BLACK, king));
    EXPECT_TRUE(dwn.move->move(occupied, BLACK, king));
    EXPECT_TRUE(right.move->move(occupied, BLACK, king));
    EXPECT_TRUE(left.move->move(occupied, BLACK, king));
}

TEST(BPow, CaptureWrong) {
    PowMock_ChessBoardSpot up;
    PowMock_ChessBoardSpot dwn;
    PowMock_ChessBoardSpot right;
    PowMock_ChessBoardSpot left;

    up.move->setCoors(4, 4, 4, 0);
    dwn.move->setCoors(4, 4, 4, 9);
    right.move->setCoors(4, 4, 0, 4);
    left.move->setCoors(4, 4, 8, 4);

    bool occupied[10][9] =
    {   {0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {1,1,0,1,1,0,0,0,1},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0},
    };

    vector<int> king = { 3,0,5,9 };
    EXPECT_FALSE(up.move->move(occupied, BLACK, king));
    EXPECT_FALSE(dwn.move->move(occupied, BLACK, king));
    EXPECT_FALSE(right.move->move(occupied, BLACK, king));
    EXPECT_FALSE(left.move->move(occupied, BLACK, king));
}

TEST(BPow, Move_XY) {
    PowMock_ChessBoardSpot p;

    p.move->setCoors(4, 4, 5, 6);

    bool occupied[10][9] =
    {   {0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };

    vector<int> king = { 3,0,5,9 };
    EXPECT_FALSE(p.move->move(occupied, BLACK, king));
}

TEST(BPow, MoveEmptyWrong) {
    PowMock_ChessBoardSpot up;
    PowMock_ChessBoardSpot dwn;
    PowMock_ChessBoardSpot right;
    PowMock_ChessBoardSpot left;

    up.move->setCoors(4, 4, 4, 0);
    dwn.move->setCoors(4, 4, 4, 9);
    right.move->setCoors(4, 4, 0, 4);
    left.move->setCoors(4, 4, 8, 4);

    bool occupied[10][9] =
    { {0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,1,0,1,1,0,0,1,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };

    vector<int> king = { 3,0,5,9 };
    EXPECT_FALSE(up.move->move(occupied, BLACK, king));
    EXPECT_FALSE(dwn.move->move(occupied, BLACK, king));
    EXPECT_FALSE(right.move->move(occupied, BLACK, king));
    EXPECT_FALSE(left.move->move(occupied, BLACK, king));
}


TEST(RPow, AllEmpty) {
    PowMock_ChessBoardSpot up;
    PowMock_ChessBoardSpot dwn;
    PowMock_ChessBoardSpot right;
    PowMock_ChessBoardSpot left;

    up.move->setCoors(4, 4, 4, 0);
    dwn.move->setCoors(4, 4, 4, 9);
    right.move->setCoors(4, 4, 0, 4);
    left.move->setCoors(4, 4, 8, 4);

    bool occupied[10][9] =
    { {0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };

    vector<int> king = { 3,0,5,9 };
    EXPECT_TRUE(up.move->move(occupied, RED, king));
    EXPECT_TRUE(dwn.move->move(occupied, RED, king));
    EXPECT_TRUE(right.move->move(occupied, RED, king));
    EXPECT_TRUE(left.move->move(occupied, RED, king));
}

TEST(RPow, CaptureCorrect) {
    PowMock_ChessBoardSpot up;
    PowMock_ChessBoardSpot dwn;
    PowMock_ChessBoardSpot right;
    PowMock_ChessBoardSpot left;

    up.move->setCoors(4, 4, 4, 0);
    dwn.move->setCoors(4, 4, 4, 9);
    right.move->setCoors(4, 4, 0, 4);
    left.move->setCoors(4, 4, 8, 4);

    bool occupied[10][9] =
    {   {0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {1,1,0,0,1,0,1,0,1},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0},
    };

    vector<int> king = { 3,0,5,9 };
    EXPECT_TRUE(up.move->move(occupied, RED, king));
    EXPECT_TRUE(dwn.move->move(occupied, RED, king));
    EXPECT_TRUE(right.move->move(occupied, RED, king));
    EXPECT_TRUE(left.move->move(occupied, RED, king));
}

TEST(RPow, CaptureWrong) {
    PowMock_ChessBoardSpot up;
    PowMock_ChessBoardSpot dwn;
    PowMock_ChessBoardSpot right;
    PowMock_ChessBoardSpot left;

    up.move->setCoors(4, 4, 4, 0);
    dwn.move->setCoors(4, 4, 4, 9);
    right.move->setCoors(4, 4, 0, 4);
    left.move->setCoors(4, 4, 8, 4);

    bool occupied[10][9] =
    {   {0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {1,1,0,1,1,0,0,0,1},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0},
    };

    vector<int> king = { 3,0,5,9 };
    EXPECT_FALSE(up.move->move(occupied, RED, king));
    EXPECT_FALSE(dwn.move->move(occupied, RED, king));
    EXPECT_FALSE(right.move->move(occupied, RED, king));
    EXPECT_FALSE(left.move->move(occupied, RED, king));
}

TEST(RPow, Move_XY) {
    PowMock_ChessBoardSpot p;

    p.move->setCoors(4, 4, 5, 6);

    bool occupied[10][9] =
    {   {0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };

    vector<int> king = { 3,0,5,9 };
    EXPECT_FALSE(p.move->move(occupied, RED, king));
}

TEST(RPow, MoveEmptyWrong) {
    PowMock_ChessBoardSpot up;
    PowMock_ChessBoardSpot dwn;
    PowMock_ChessBoardSpot right;
    PowMock_ChessBoardSpot left;

    up.move->setCoors(4, 4, 4, 0);
    dwn.move->setCoors(4, 4, 4, 9);
    right.move->setCoors(4, 4, 0, 4);
    left.move->setCoors(4, 4, 8, 4);

    bool occupied[10][9] =
    { {0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,1,0,1,1,0,0,1,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };

    vector<int> king = { 3,0,5,9 };
    EXPECT_FALSE(up.move->move(occupied, RED, king));
    EXPECT_FALSE(dwn.move->move(occupied, RED, king));
    EXPECT_FALSE(right.move->move(occupied, RED, king));
    EXPECT_FALSE(left.move->move(occupied, RED, king));
}


#endif
