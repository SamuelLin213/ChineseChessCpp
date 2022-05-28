#ifndef ELEPHANT_TEST_HPP__
#define ELEPHANT_TEST_HPP__

#include "gtest/gtest.h"

#include "validMove.h"
#include "MockClass.h"

TEST(BElephantTest, CorrectMove) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(2, 0, 4, 2);

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


TEST(BElephantTest, MiddlePiece) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(3, 0, 5, 2);

    bool occupied[10][9] =
    {   {0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
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
    EXPECT_FALSE(e.move->move(occupied, BLACK, king));
}


TEST(BElephantTest, OverRiver) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(4, 3, 6, 5);

    bool occupied[10][9] =
    {   {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_FALSE(e.move->move(occupied, BLACK, king));
}


TEST(BElephantTest, OneOver2Down) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(3, 0, 4, 2);

    bool occupied[10][9] =
    {   {0,0,0,1,1,0,0,0,0},
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
    EXPECT_FALSE(e.move->move(occupied, BLACK, king));
}


TEST(BElephantTest, 2DownOneOVer) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(3, 0, 5, 1);

    bool occupied[10][9] =
    {   {0,0,0,1,1,0,0,0,0},
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
    EXPECT_FALSE(e.move->move(occupied, BLACK, king));
}


TEST(BElephantTest, OneSpace) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(3, 0, 4, 1);

    bool occupied[10][9] =
    {   {0,0,0,1,1,0,0,0,0},
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
    EXPECT_FALSE(e.move->move(occupied, BLACK, king));
}


TEST(RElephantTest, CorrectMove) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(2, 9, 0, 7);

    bool occupied[10][9] =
    {   {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_TRUE(e.move->move(occupied, RED, king));
}


TEST(RElephantTest, MiddlePiece) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(0, 7, 2, 9);

    bool occupied[10][9] =
    {   {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_FALSE(e.move->move(occupied, RED, king));
}

TEST(RElephantTest, OverRiver) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(6, 6, 8, 4);

    bool occupied[10][9] =
    {   {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_FALSE(e.move->move(occupied, RED, king));
}


TEST(RElephantTest, OneOver2Down) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(5, 5, 6, 7);

    bool occupied[10][9] =
    {   {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_FALSE(e.move->move(occupied, RED, king));
}

TEST(RElephantTest, 2OverOnedown) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(3, 7, 5, 8);

    bool occupied[10][9] =
    {   {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_FALSE(e.move->move(occupied, RED, king));
}


TEST(RElephantTest, OneSpace) {
    ElephantMock_ChessBoardSpot e;
    e.move->setCoors(1, 9, 2, 8);

    bool occupied[10][9] =
    {   {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_FALSE(e.move->move(occupied, RED, king));
}


#endif
