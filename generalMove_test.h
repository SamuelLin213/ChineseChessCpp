#ifndef GENERAL_TEST_HPP
#define GENERAL_TEST_HPP

#include "gtest/gtest.h"

#include "validMove.h"
#include "MockClass.h"

TEST(BGeneralTest, BG_Fwd_Empty) {
    GeneralMock_ChessBoardSpot g;
    g.move->setCoors(4, 1, 4, 2);

    bool occupied[10][9] =
    { {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4,1,4,9 };
    EXPECT_TRUE(g.move->move(occupied, BLACK, king));
}

TEST(BGeneralTest, BG_Right_Empty) {
    GeneralMock_ChessBoardSpot g;
    g.move->setCoors(4, 1, 5, 1);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4,1,4,9 };
    EXPECT_TRUE(g.move->move(occupied, BLACK, king));
}


TEST(BGeneralTest, BG_np_RG) {
    GeneralMock_ChessBoardSpot g;
    g.move->setCoors(4, 1, 4, 2);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
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

    vector<int> king = { 4, 1, 4, 9};
    EXPECT_FALSE(g.move->move(occupied, BLACK, king));
}

TEST(BGeneralTest, BG_p_RG) {
    GeneralMock_ChessBoardSpot g;
    g.move->setCoors(4, 1, 4, 2);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9};
    EXPECT_TRUE(g.move->move(occupied, BLACK, king));
}

TEST(BGeneralTest, BG_XOutofPalace) {
    GeneralMock_ChessBoardSpot g;
    g.move->setCoors(4, 1, 6, 2);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
    };

    vector<int> king = { 4, 1, 5, 9 };
    EXPECT_FALSE(g.move->move(occupied, BLACK, king));
}

TEST(BGeneralTest, BG_YOutofPalace) {
    GeneralMock_ChessBoardSpot g;
    g.move->setCoors(4, 1, 4, 3);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
    };

    vector<int> king = { 4, 1, 5, 9 };
    EXPECT_FALSE(g.move->move(occupied, BLACK, king));
}

TEST(BGeneralTest, BG_2SpacesX) {
    GeneralMock_ChessBoardSpot g;
    g.move->setCoors(3, 0, 5, 0);

    bool occupied[10][9] =
    {   {0,0,0,1,0,0,0,0,0},
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

    vector<int> king = { 3, 0, 4, 9 };
    EXPECT_FALSE(g.move->move(occupied, BLACK, king));
}

TEST(BGeneralTest, BG_2SpacesY) {
    GeneralMock_ChessBoardSpot g;
    g.move->setCoors(3, 0, 3, 2);

    bool occupied[10][9] =
    {   {0,0,0,1,0,0,0,0,0},
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

    vector<int> king = { 3, 0, 4, 9 };
    EXPECT_FALSE(g.move->move(occupied, BLACK, king));
}

TEST(RGeneralTest, RG_Fwd_Empty) {
    GeneralMock_ChessBoardSpot rg;
    rg.move->setCoors(4, 9, 4, 8);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 3, 1, 4, 9 };
    EXPECT_TRUE(rg.move->move(occupied, RED, king));
}


TEST(RGeneralTest, RG_Right_Empty) {
    GeneralMock_ChessBoardSpot rg;
    rg.move->setCoors(4, 9, 5, 9);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 3, 1, 4, 9 };
    EXPECT_TRUE(rg.move->move(occupied, RED, king));
}


TEST(RGeneralTest, RG_np_RG) {
    GeneralMock_ChessBoardSpot rg;
    rg.move->setCoors(4, 9, 4, 8);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
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
    EXPECT_FALSE(rg.move->move(occupied, RED, king));
}

TEST(RGeneralTest, RG_p_RG) {
    GeneralMock_ChessBoardSpot rg;
    rg.move->setCoors(4, 9, 4, 8);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 4, 1, 4, 9 };
    EXPECT_TRUE(rg.move->move(occupied, RED, king));
}

TEST(RGeneralTest, RG_XOutofPalace) {
    GeneralMock_ChessBoardSpot rg;
    rg.move->setCoors(4, 9, 2, 8);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
    };

    vector<int> king = { 3, 1, 4, 9 };
    EXPECT_FALSE(rg.move->move(occupied, RED, king));
}

TEST(RGeneralTest, RG_YOutofPalace) {
    GeneralMock_ChessBoardSpot rg;
    rg.move->setCoors(4, 9, 4, 6);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
    };

    vector<int> king = { 4, 1, 5, 9 };
    EXPECT_FALSE(rg.move->move(occupied, RED, king));
}

TEST(RGeneralTest, RG_2SpacesX) {
    GeneralMock_ChessBoardSpot rg;
    rg.move->setCoors(3, 9, 5, 9);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0},
    };

    vector<int> king = { 4, 1, 3, 9 };
    EXPECT_FALSE(rg.move->move(occupied, RED, king));
}

TEST(RGeneralTest, RG_2SpacesY) {
    GeneralMock_ChessBoardSpot rg;
    rg.move->setCoors(3, 9, 3, 7);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0},
    };

    vector<int> king = { 4, 1, 3, 9 };
    EXPECT_FALSE(rg.move->move(occupied, RED, king));
}


#endif 
