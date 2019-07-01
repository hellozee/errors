#include <gtest/gtest.h>
#include <errors.h>
#include <vector>

TEST(ErrorsTest, WhatString){
    std::string s("just testing");
    auto e = errors::new_error(s.c_str());
    EXPECT_EQ(s, e.what());
}

TEST(ErrorsTest, EqualAndNil){
    auto e = errors::nil();
    EXPECT_EQ(e, errors::nil());
}

TEST(ErrorsTest, NotEqual){
    auto e1 = errors::new_error("just testing");
    EXPECT_NE(e1, errors::nil());
}

class Class
{
public:
    bool copied = false;
    bool moved = false;

    Class() {}

    Class(const Class& c)
    {
        copied = true;
    }

    Class(Class&& c)
    {
        moved = true;
    }
};

errors::container<std::vector<Class>> getVector()
{
    std::vector<Class> result;

    result.push_back(Class());

    return errors::container<std::vector<Class>>(std::move(result), errors::nil());
}

TEST(ErrorsTest, Container) {
    auto container = getVector();

    EXPECT_EQ(container.err(), errors::nil());
    EXPECT_EQ(container.object()[0].copied, false);
    EXPECT_EQ(container.object()[0].moved, true);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
