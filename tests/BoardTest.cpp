//
// Created by daniel on 28/11/17.
//

#include <gtest/gtest.h>
#include "../src/Board.h"

TEST(Board, BoardSizeTest) {
    Board b(8);
    EXPECT_EQ(b.getSize(), 8);
    Board c(2);
    EXPECT_EQ(c.getSize(), 2);
}
