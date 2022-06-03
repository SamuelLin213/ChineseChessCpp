#ifndef SOLDIER_TEST_HPP__
#define SOLDIER_TEST_HPP__

#include "gtest/gtest.h"

#include "validMove.h"
#include "MockClass.h"

TEST(SolderValidMoveBlack, blackMoveAhead) 
{
    SoldierMock_ChessBoardSpot soldierObject;
    //               c  r  c  r
    soldierObject.move->setCoors(2, 0, 2, 1); 

    bool occupied[10][9] =
    {   {0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
    };

    vector<int> king = { 7, 1, 7, 9 };
    EXPECT_TRUE(soldierObject.move->move(occupied, BLACK, king));
}

TEST(SolderValidMoveBlack, blackPassRiver) 
{
    SoldierMock_ChessBoardSpot soldierObject;
    //               c  r  c  r
    soldierObject.move->setCoors(4, 4, 4, 5); 

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
    };

    vector<int> king = { 7, 1, 7, 9 };
    EXPECT_TRUE(soldierObject.move->move(occupied, BLACK, king));
}

TEST(SolderInvalidMoveBlack, blackMoveBackwards) 
{
    SoldierMock_ChessBoardSpot soldierObject;
    //               c  r  c  r
    soldierObject.move->setCoors(4, 4, 4, 3); 

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
    };

    vector<int> king = { 7, 1, 7, 9 };
    EXPECT_FALSE(soldierObject.move->move(occupied, BLACK, king));
}

TEST(SolderInvalidMoveBlack, blackMoveLeft) 
{
    SoldierMock_ChessBoardSpot soldierObject;
    //               c  r  c  r
    soldierObject.move->setCoors(4, 4, 3, 4); 

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
    };

    vector<int> king = { 7, 1, 7, 9 };
    EXPECT_FALSE(soldierObject.move->move(occupied, BLACK, king));
}

TEST(SolderInvalidMoveBlack, blackMoveRight) 
{
    SoldierMock_ChessBoardSpot soldierObject;
    //               c  r  c  r
    soldierObject.move->setCoors(4, 4, 5, 4); 

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
    };

    vector<int> king = { 7, 1, 7, 9 };
    EXPECT_FALSE(soldierObject.move->move(occupied, BLACK, king));
}

TEST(SolderValidMoveRed, redMoveAhead) 
{
    SoldierMock_ChessBoardSpot soldierObject;
    //                           c  r  c  r
    soldierObject.move->setCoors(2, 8, 2, 7); 

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
    };

    vector<int> king = { 7, 1, 7, 9 };
    EXPECT_TRUE(soldierObject.move->move(occupied, RED, king));
}

TEST(SolderInvalidMoveRed, redMoveBackwards) 
{
    SoldierMock_ChessBoardSpot soldierObject;
    //                           c  r  c  r
    soldierObject.move->setCoors(2, 8, 2, 9); 

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
    };

    vector<int> king = { 7, 1, 7, 9 };
    EXPECT_FALSE(soldierObject.move->move(occupied, RED, king));
}

TEST(SolderInvalidMoveRed, redMoveLeft) 
{
    SoldierMock_ChessBoardSpot soldierObject;
    //                           c  r  c  r
    soldierObject.move->setCoors(2, 8, 1, 8); 

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
    };

    vector<int> king = { 7, 1, 7, 9 };
    EXPECT_FALSE(soldierObject.move->move(occupied, RED, king));
}

TEST(SolderInvalidMoveRed, redMoveRight) 
{
    SoldierMock_ChessBoardSpot soldierObject;
    //                           c  r  c  r
    soldierObject.move->setCoors(2, 8, 3, 8); 

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,0},
    };

    vector<int> king = { 7, 1, 7, 9 };
    EXPECT_FALSE(soldierObject.move->move(occupied, RED, king));
}

#endif