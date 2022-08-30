#include "../function.hpp"

#include <random>
#include <algorithm>

#include <gtest/gtest.h>

const int kSize = 10000;

int RandNumberBetween(int low, int high) {
    static std::mt19937 random_engine{std::random_device{}()};
    static std::uniform_int_distribution<int> dist;
    return dist(random_engine, std::uniform_int_distribution<int>::param_type{low, high});
}

void getDataSet(int low, int high, int* ar1, int* ar2) {
    for (int i = 0; i < kSize; ++i) {
        ar1[i] = RandNumberBetween(low, high);
        ar2[i] = RandNumberBetween(low, high);
    }
}

TEST(SortLess, Positive) {
    auto comp = [](int a, int b) { return a < b; };
    int* slow_arr = new int[kSize];
    int* arr = new int[kSize];
    int* test_arr = new int[kSize];
    int* test_slow_arr = new int[kSize];
    getDataSet(0, 10000, arr, slow_arr);

    std::copy(arr, arr + kSize, test_arr);
    std::copy(slow_arr, slow_arr + kSize, test_slow_arr);

    my_slow_sort(slow_arr, kSize, comp);
    std::sort(test_slow_arr, test_slow_arr + kSize, std::less<>());

    my_sort(arr, kSize, comp);
    std::sort(test_arr, test_arr + kSize, std::less<>());

    ASSERT_TRUE(std::equal(test_arr, test_arr + kSize, arr));
    ASSERT_TRUE(std::equal(test_slow_arr, test_slow_arr + kSize, slow_arr));
}

TEST(SortLess, Negative) {
    auto comp = [](int a, int b) { return a < b; };
    int* slow_arr = new int[kSize];
    int* arr = new int[kSize];
    int* test_arr = new int[kSize];
    int* test_slow_arr = new int[kSize];
    getDataSet(-50000, 0, arr, slow_arr);

    std::copy(arr, arr + kSize, test_arr);
    std::copy(slow_arr, slow_arr + kSize, test_slow_arr);

    my_slow_sort(slow_arr, kSize, comp);
    std::sort(test_slow_arr, test_slow_arr + kSize, std::less<>());

    my_sort(arr, kSize, comp);
    std::sort(test_arr, test_arr + kSize, std::less<>());

    ASSERT_TRUE(std::equal(test_arr, test_arr + kSize, arr));
    ASSERT_TRUE(std::equal(test_slow_arr, test_slow_arr + kSize, slow_arr));
}

TEST(SortGreater, Positive) {
    auto comp = [](int a, int b) { return a > b; };
    int* slow_arr = new int[kSize];
    int* arr = new int[kSize];
    int* test_arr = new int[kSize];
    int* test_slow_arr = new int[kSize];
    getDataSet(0, 100000, arr, slow_arr);

    std::copy(arr, arr + kSize, test_arr);
    std::copy(slow_arr, slow_arr + kSize, test_slow_arr);

    my_slow_sort(slow_arr, kSize, comp);
    std::sort(test_slow_arr, test_slow_arr + kSize, std::greater<>());

    my_sort(arr, kSize, comp);
    std::sort(test_arr, test_arr + kSize, std::greater<>());

    ASSERT_TRUE(std::equal(test_arr, test_arr + kSize, arr));
    ASSERT_TRUE(std::equal(test_slow_arr, test_slow_arr + kSize, slow_arr));
}

TEST(SortGreater, Negative) {
    auto comp = [](int a, int b) { return a > b; };
    int* slow_arr = new int[kSize];
    int* arr = new int[kSize];
    int* test_arr = new int[kSize];
    int* test_slow_arr = new int[kSize];
    getDataSet(-100000, -10000, arr, slow_arr);

    std::copy(arr, arr + kSize, test_arr);
    std::copy(slow_arr, slow_arr + kSize, test_slow_arr);

    my_slow_sort(slow_arr, kSize, comp);
    std::sort(test_slow_arr, test_slow_arr + kSize, std::greater<>());

    my_sort(arr, kSize, comp);
    std::sort(test_arr, test_arr + kSize, std::greater<>());

    ASSERT_TRUE(std::equal(test_arr, test_arr + kSize, arr));
    ASSERT_TRUE(std::equal(test_slow_arr, test_slow_arr + kSize, slow_arr));
}

TEST(RandomSort, Random) {
    auto comp1 = [](int a, int b) { return a*a < b*b; };
    auto comp2 = [](int a, int b) { return abs(a) < abs(b); };
    int* slow_arr = new int[kSize];
    int* slow_arr1 = new int[kSize];
    int* arr = new int[kSize];
    int* arr1 = new int[kSize];

    int* test_arr = new int[kSize];
    int* test_arr1 = new int[kSize];
    int* test_slow_arr = new int[kSize];
    int* test_slow_arr1 = new int[kSize];

    int* st_test_arr = new int[kSize];
    int* st_test_arr1 = new int[kSize];
    int* st_test_slow_arr = new int[kSize];
    int* st_test_slow_arr1 = new int[kSize];

    getDataSet(-100000, 100000, arr, slow_arr);
    getDataSet(-100000, 100000, arr1, slow_arr1);

    std::copy(arr, arr + kSize, test_arr);
    std::copy(arr1, arr1 + kSize, test_arr1);
    std::copy(slow_arr, slow_arr + kSize, test_slow_arr);
    std::copy(slow_arr1, slow_arr1 + kSize, test_slow_arr1);

    std::copy(test_arr, test_arr + kSize, st_test_arr);
    std::copy(test_arr1, test_arr1 + kSize, st_test_arr1);
    std::copy(test_slow_arr, test_slow_arr + kSize, st_test_slow_arr);
    std::copy(test_slow_arr1, test_slow_arr1 + kSize, st_test_slow_arr1);

    my_slow_sort(slow_arr, kSize, comp1);
    std::sort(test_slow_arr, test_slow_arr + kSize, comp1);

    my_slow_sort(slow_arr1, kSize, comp2);
    std::sort(test_slow_arr1, test_slow_arr1 + kSize, comp2);

    my_sort(arr, kSize, comp1);
    std::sort(test_arr, test_arr + kSize, comp1);

    my_sort(arr1, kSize, comp2);
    std::sort(test_arr1, test_arr1 + kSize, comp2);

    if (!std::equal(test_arr, test_arr + kSize, arr, [](int a, int b) { return abs(a) == abs(b); })) {
        std::stable_sort(st_test_arr, st_test_arr + kSize, comp1);
        ASSERT_TRUE(std::equal(st_test_arr, st_test_arr + kSize, arr));
    } else { ASSERT_TRUE(true); }
    if (!std::equal(test_slow_arr, test_slow_arr + kSize, slow_arr, [](int a, int b) { return abs(a) == abs(b); })) {
        std::stable_sort(st_test_slow_arr, st_test_slow_arr + kSize, comp1);
        ASSERT_TRUE(std::equal(st_test_slow_arr, st_test_slow_arr + kSize, slow_arr));
    } else { ASSERT_TRUE(true); }
    if(!std::equal(test_arr1, test_arr1 + kSize, arr1, [](int a, int b){ return abs(a) == abs(b); })) {
        std::stable_sort(st_test_arr1, st_test_arr1 + kSize, comp2);
        ASSERT_TRUE(std::equal(st_test_arr1, st_test_arr1 + kSize, arr1));
    } else { ASSERT_TRUE(true); }
    if (!std::equal(test_slow_arr1, test_slow_arr1 + kSize, slow_arr1, [](int a, int b){ return abs(a) == abs(b); })) {
        std::stable_sort(st_test_slow_arr1, st_test_slow_arr1 + kSize, comp2);
        ASSERT_TRUE(std::equal(st_test_slow_arr1, st_test_slow_arr1 + kSize, slow_arr1));
    } else { ASSERT_TRUE(true); }
}