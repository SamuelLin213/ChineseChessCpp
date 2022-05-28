#ifndef ADVISOR_TEST_HPP
#define ADVISOR_TEST_HPP

#include "gtest/gtest.h"

#include "validMove.h"
#include "MockClass.h"


TEST(BAdvisorTest, BA_RDiag) {
    AdvisorMock_ChessBoardSpot ba;
    ba.move->setCoors(4, 1, 5, 2);

    bool occupied[10][9] =
    {   {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };

    vector<int> king = { 4, 0, 5, 9 };
    EXPECT_TRUE(ba.move->move(occupied, BLACK, king));
}

TEST(BAdvisorTest, BA_LDiag) {
    AdvisorMock_ChessBoardSpot ba;
    ba.move->setCoors(4, 1, 3, 0);

    bool occupied[10][9] =
    {   {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };
    vector<int> king = { 4, 0, 5, 9 };
    EXPECT_TRUE(ba.move->move(occupied, BLACK, king));
}


TEST(BAdvisorTest, BA_OutofPalace) {
    AdvisorMock_ChessBoardSpot ba;
    ba.move->setCoors(5, 2, 6, 3);

    bool occupied[10][9] =
    {   {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };

    vector<int> king = { 4, 1, 5, 9 };
    EXPECT_FALSE(ba.move->move(occupied, BLACK, king));
}

TEST(BAdvisorTest, BA_NotDiagonal) {
    AdvisorMock_ChessBoardSpot ba;
    ba.move->setCoors(4, 1, 4, 3);

    bool occupied[10][9] =
    {   {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };
    vector<int> king = { 4, 0, 5, 9 };
    EXPECT_FALSE(ba.move->move(occupied, BLACK, king));
}


TEST(BAdvisorTest, BA_MoreThanOne) {
    AdvisorMock_ChessBoardSpot ba;
    ba.move->setCoors(3, 0, 5, 2);

    bool occupied[10][9] =
    {   {0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };
    vector<int> king = { 4, 1, 5, 9 };
    EXPECT_FALSE(ba.move->move(occupied, BLACK, king));
}

TEST(RAdvisorTest, RA_RDiag) {
    AdvisorMock_ChessBoardSpot ra;
    ra.move->setCoors(3, 9, 4, 8);

    bool occupied[10][9] =
    {   {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,1,0,1,0,0,0},
    };

    vector<int> king = { 4, 0, 5, 9 };
    EXPECT_TRUE(ra.move->move(occupied, RED, king));
}

TEST(RAdvisorTest, RA_LDiag) {
    AdvisorMock_ChessBoardSpot ra;
    ra.move->setCoors(5, 7, 4, 8);

    bool occupied[10][9] =
    { {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };
    vector<int> king = { 4, 0, 5, 9 };
    EXPECT_TRUE(ra.move->move(occupied, RED, king));
}

TEST(RAdvisorTest, RA_OutofPalace) {
    AdvisorMock_ChessBoardSpot ra;
    ra.move->setCoors(5, 7, 6, 6);

    bool occupied[10][9] =
    { {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };

    vector<int> king = { 4, 1, 5, 9 };
    EXPECT_FALSE(ra.move->move(occupied, RED, king));
}

TEST(RAdvisorTest, RA_NotDiagonal) {
    AdvisorMock_ChessBoardSpot ra;
    ra.move->setCoors(4, 8, 4, 7);

    bool occupied[10][9] =
    { {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };
    vector<int> king = { 4, 0, 5, 9 };
    EXPECT_FALSE(ra.move->move(occupied, RED, king));
}


TEST(RAdvisorTest, RA_MoreThanOne) {
    AdvisorMock_ChessBoardSpot ra;
    ra.move->setCoors(3, 9, 5, 7);

    bool occupied[10][9] =
    { {0,0,0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
    };
    vector<int> king = { 4, 1, 5, 9 };
    EXPECT_FALSE(ra.move->move(occupied, RED, king));
}


#endif
