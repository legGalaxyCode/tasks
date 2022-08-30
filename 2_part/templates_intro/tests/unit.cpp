#include <climits>

#include <gtest/gtest.h>

#include "../array.hpp"

TEST(SizeTest, BasicAssertions) {
    Array<int> array(100);
    try {
        Array<double> array1(INT_MAX, INT_MAX);
    } catch (std::exception& e) {
        std::cout << e.what();
        EXPECT_EQ(e.what(), "std::bad_alloc");
    }
    EXPECT_EQ(array.size(), 100);
    EXPECT_EQ(sizeof(array), sizeof(int) * 100);
}

TEST(AccessTest, BasicAssertions) {
    Array<int> array(5, 4);
    for (int i = 0; i < array.size(); ++i)
        ASSERT_EQ(array[i], 4);
    array[3] = 123;
    EXPECT_EQ(array[3], 123);
    array[0] = INT_MAX;
    EXPECT_EQ(array[0], INT_MAX);
}

TEST(TypesTest, BasicAssertions) {
    struct Student {
        int id{};
        std::string name;
        Student(int id, std::string name): id(id), name(std::move(name)) {}
        Student(): id(0) {}
    };
    Array<double> d_array(10);
    Array<std::string> str_array(10);
    Array<Student> stud_array(10);

    d_array[0] = 3.14;
    d_array[1] = DBL_MAX;
    d_array[2] = DBL_MIN;
    EXPECT_EQ(d_array[0], 3.14);
    EXPECT_EQ(d_array[1], DBL_MAX);
    EXPECT_EQ(d_array[2], DBL_MIN);

    str_array[0] = "absbasdasda";
    str_array[1] = "привет";
    str_array[str_array.size() - 1] = "a";
    EXPECT_EQ(str_array[0], "absbasdasda");
    EXPECT_EQ(str_array[1], "привет");
    EXPECT_EQ(str_array[2], "");
    EXPECT_EQ(str_array[str_array.size() - 1], "a");

    stud_array[0] = {3, "Vasya"};
    EXPECT_EQ(stud_array[0].id, 3);
    EXPECT_EQ(stud_array[0].name, "Vasya");
}