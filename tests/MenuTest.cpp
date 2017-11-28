//
// Created by shlomi on 11/28/17.
//

#include <gtest/gtest.h>
#include "../src/Menu.h"

Menu m;

TEST(Menu, CheckInput) {

    EXPECT_EQ(m.againstHuman(), false);
    EXPECT_EQ(m.againstAI(), false);

}

TEST(Menu, MenuLoop) {
    ASSERT_NO_THROW(m.runMenu());
}

TEST(Menu, HumanResult) {
    EXPECT_TRUE(m.againstHuman());
}

TEST(Menu, AIResult) {
    EXPECT_FALSE(m.againstAI());
}