#include <iostream>
#include <gtest/gtest.h>
#include <errors>

TEST(ErrorsTest, WhatString) {
    std::string s("just testing");
    auto e = errors::new_error(s); 
    EXPECT_EQ(s, e.what());
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
