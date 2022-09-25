#include "../classes.hpp"

#include <climits>

#include <gtest/gtest.h>

LinkedList list1_;
LinkedList list2_{2, 10};

TEST(ListTest, Empty) {
    ASSERT_TRUE(list1_.empty());
    ASSERT_FALSE(list2_.empty());
}

TEST(ListTest, SizeAndInsert) {
    ASSERT_EQ(list1_.size(), 0);
    ASSERT_EQ(list2_.size(), 2);

    for (int i = 0; i < 100; ++i) {
        list1_.push_back(i);
    }
    ASSERT_EQ(list1_.size(), 100);

    for (int i = 0; i < 50; ++i)
        list2_.push_front(i * 2);
    ASSERT_EQ(list2_.size(), 52);
}

TEST(ListTest, Remove) {
    for (int i = 0; i < 99; ++i)
        list1_.pop_back();
    ASSERT_EQ(list1_.size(), 1);

    for (int i = 0; i < 40; ++i)
        list2_.remove(i * 2);
    ASSERT_EQ(list2_.size(), 10);
}

TEST(ListTest, Find) {
    ASSERT_TRUE(list1_.find(0));
    ASSERT_FALSE(list1_.find(10));
    ASSERT_FALSE(list1_.find(4));

    ASSERT_FALSE(list2_.find(10));
    ASSERT_TRUE(list2_.find(90));
    ASSERT_TRUE(list2_.find(94));

    list1_.push_front(-354);
    ASSERT_TRUE(list1_.find(-354));

    list2_.push_front(INT_MIN + 100);
    ASSERT_TRUE(list2_.find(INT_MIN + 100))
}