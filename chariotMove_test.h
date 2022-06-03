#ifndef CHARIOT_TEST_HPP
#define CHARIOT_TEST_HPP

#include "gtest/gtest.h"
#include "validMove.h"
#include "MockClass.h"

TEST(ChariotMove, DirectionalMove) {
    ChariotMock_ChessBoardSpot up;
    ChariotMock_ChessBoardSpot dwn;
    ChariotMock_ChessBoardSpot right;
    ChariotMock_ChessBoardSpot left;

    up.move->setCoors(4, 4, 4, 0);
    dwn.move->setCoors(4, 4, 4, 9);
    right.move->setCoors(4, 4, 0, 4);
    left.move->setCoors(4, 4, 8, 4);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
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

TEST(ChariotMove, CaptureCorrect) {
    ChariotMock_ChessBoardSpot up;
    ChariotMock_ChessBoardSpot dwn;
    ChariotMock_ChessBoardSpot right;
    ChariotMock_ChessBoardSpot left;

    up.move->setCoors(4, 4, 4, 0);
    dwn.move->setCoors(4, 4, 4, 9);
    right.move->setCoors(4, 4, 0, 4);
    left.move->setCoors(4, 4, 8, 4);

    bool occupied[10][9] =
    {   {0,0,0,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {1,0,0,0,1,0,0,0,1},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0},
    };

    vector<int> king = { 3,0,5,9 };
    EXPECT_TRUE(up.move->move(occupied, BLACK, king));
    EXPECT_TRUE(dwn.move->move(occupied, BLACK, king));
    EXPECT_TRUE(right.move->move(occupied, BLACK, king));
    EXPECT_TRUE(left.move->move(occupied, BLACK, king));
}

TEST(ChariotMove, CaptureInvalid) {
    ChariotMock_ChessBoardSpot up;
    ChariotMock_ChessBoardSpot dwn;
    ChariotMock_ChessBoardSpot right;
    ChariotMock_ChessBoardSpot left;

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
    EXPECT_FALSE(up.move->move(occupied, BLACK, king));
    EXPECT_FALSE(dwn.move->move(occupied, BLACK, king));
    EXPECT_FALSE(right.move->move(occupied, BLACK, king));
    EXPECT_FALSE(left.move->move(occupied, BLACK, king));
}

TEST(ChariotMove, MoveDiagonal) {
    ChariotMock_ChessBoardSpot diag;

    diag.move->setCoors(4, 4, 5, 3);
     
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

    vector<int> king = { 3,0,5,9};
    EXPECT_FALSE(diag.move->(occupied, BLACK, king));
}

#endif
