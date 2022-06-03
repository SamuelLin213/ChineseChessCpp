#ifndef SOLDIER_TEST_HPP__
#define SOLDIER_TEST_HPP__

#include "gtest/gtest.h"

#include "validMove.h"
#include "MockClass.h"

TEST(SolderValidMove, moveAhead) 
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

TEST(SolderValidMove, passRiver) 
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

TEST(SolderInvalidMove, MoveBackwards) 
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

TEST(SolderInvalidMove, MoveLeft) 
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

TEST(SolderInvalidMove, MoveRight) 
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

#endif