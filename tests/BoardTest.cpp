//
// Created by daniel on 28/11/17.
//

#include <gtest/gtest.h>
#include "../src/Board.h"

TEST(Board, BoardSizeTest) {
    Board b(8);
    b.put(Black, 5, 4);
    EXPECT_EQ(b.getSize(), 8);
    Board c(2);
    EXPECT_EQ(c.getSize(), 2);
}

TEST(Board, EqualTest) {
    //create same size board.
    Board a(10);
    Board b(10);
    EXPECT_TRUE(a == b);
    //put the same for black.
    a.put(Black, 8, 8);
    b.put(Black, 8, 8);
    EXPECT_TRUE(a == b);
    //put the same for white.
    a.put(White, 1, 1);
    b.put(White, 1, 1);
    EXPECT_TRUE(a == b);
    //put different for black.
    a.put(Black, 1, 8);
    b.put(Black, 8, 1);
    EXPECT_FALSE(a == b);
    //make board equal.
    a.put(Black, 8, 1);
    b.put(Black, 1, 8);
    EXPECT_TRUE(a == b);
    //put different for white.
    a.put(White, 2, 1);
    b.put(White, 2, 2);
    EXPECT_FALSE(a == b);
    //make board equal.
    a.put(White, 2, 2);
    b.put(White, 2, 1);

    //create different size boards.
    Board c(5);
    Board d(6);
    EXPECT_FALSE(c == d);
}

TEST(Board, CopyConstructorTest) {
    Board a(8);
    Board b(a);
    EXPECT_TRUE(a == b);
    Board c(7);
    Board d(a);
    EXPECT_FALSE(c == d);
}

TEST(Board, GetSquareTest) {
    Board b(10);
    EXPECT_EQ(b.getSquare(5, 5), White);
    EXPECT_EQ(b.getSquare(0, 0), Empty);
    b.put(Black, 1, 1);
    EXPECT_EQ(b.getSquare(1, 1), Black);
    b.put(White, 2, 2);
    EXPECT_EQ(b.getSquare(2, 2), White);
}