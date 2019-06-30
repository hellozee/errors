#include <iostream>
#include <gtest/gtest.h>
#include <errors.h>

TEST(ErrorsTest, WhatString) {
    std::string s("just testing");
    auto e = errors::new_error(s); 
    EXPECT_EQ(s, e.what());
}

TEST(ErrorsTest, EqualAndNil) {
    auto e = errors::nil();
    EXPECT_EQ(e, errors::nil());
}

TEST(ErrorsTest, NotEqual) {
    auto e1 = errors::new_error("just testing");
    EXPECT_NE(e1, errors::nil());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
