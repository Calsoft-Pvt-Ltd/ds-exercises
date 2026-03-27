#include <gtest/gtest.h>
#include "fixed_array.h"

// --- Initialization ---

TEST(FixedArrayTest, InitialSizeIsZero) {
    FixedArray arr(5);
    EXPECT_EQ(arr.size(), 0);
}

// --- Insert ---

TEST(FixedArrayTest, InsertSingleElement) {
    FixedArray arr(5);
    arr.insert(0, 42);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr.get(0), 42);
}

TEST(FixedArrayTest, InsertAtBeginningShiftsRight) {
    FixedArray arr(5);
    arr.insert(0, 1);
    arr.insert(0, 2);
    EXPECT_EQ(arr.get(0), 2);
    EXPECT_EQ(arr.get(1), 1);
}

TEST(FixedArrayTest, InsertAtEnd) {
    FixedArray arr(5);
    arr.insert(0, 1);
    arr.insert(1, 2);
    EXPECT_EQ(arr.get(1), 2);
}

TEST(FixedArrayTest, InsertAtMiddle) {
    FixedArray arr(5);
    arr.insert(0, 1);
    arr.insert(1, 3);
    arr.insert(1, 2);
    EXPECT_EQ(arr.get(0), 1);
    EXPECT_EQ(arr.get(1), 2);
    EXPECT_EQ(arr.get(2), 3);
}

TEST(FixedArrayTest, InsertThrowsWhenFull) {
    FixedArray arr(2);
    arr.insert(0, 1);
    arr.insert(1, 2);
    EXPECT_THROW(arr.insert(2, 3), std::overflow_error);
}

TEST(FixedArrayTest, InsertThrowsOnNegativeIndex) {
    FixedArray arr(5);
    EXPECT_THROW(arr.insert(-1, 1), std::out_of_range);
}

TEST(FixedArrayTest, InsertThrowsOnIndexBeyondSize) {
    FixedArray arr(5);
    // size is 0; only index 0 is valid
    EXPECT_THROW(arr.insert(1, 1), std::out_of_range);
}

// --- Get ---

TEST(FixedArrayTest, GetThrowsOnNegativeIndex) {
    FixedArray arr(5);
    arr.insert(0, 10);
    EXPECT_THROW(arr.get(-1), std::out_of_range);
}

TEST(FixedArrayTest, GetThrowsOnIndexAtSize) {
    FixedArray arr(5);
    arr.insert(0, 10);
    EXPECT_THROW(arr.get(1), std::out_of_range);
}

// --- Delete ---

TEST(FixedArrayTest, DeleteAtReducesSizeAndShifts) {
    FixedArray arr(5);
    arr.insert(0, 1);
    arr.insert(1, 2);
    arr.deleteAt(0);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr.get(0), 2);
}

TEST(FixedArrayTest, DeleteAtThrowsWhenEmpty) {
    FixedArray arr(5);
    EXPECT_THROW(arr.deleteAt(0), std::out_of_range);
}

TEST(FixedArrayTest, DeleteAtThrowsOnInvalidIndex) {
    FixedArray arr(5);
    arr.insert(0, 1);
    EXPECT_THROW(arr.deleteAt(1), std::out_of_range);
}

// --- Find ---

TEST(FixedArrayTest, FindReturnsCorrectIndex) {
    FixedArray arr(5);
    arr.insert(0, 10);
    arr.insert(1, 20);
    arr.insert(2, 30);
    EXPECT_EQ(arr.find(20), 1);
}

TEST(FixedArrayTest, FindReturnsMinusOneWhenAbsent) {
    FixedArray arr(5);
    arr.insert(0, 10);
    EXPECT_EQ(arr.find(99), -1);
}

TEST(FixedArrayTest, FindReturnsFirstOccurrence) {
    FixedArray arr(5);
    arr.insert(0, 5);
    arr.insert(1, 5);
    EXPECT_EQ(arr.find(5), 0);
}

// --- Rotate Right ---

TEST(FixedArrayTest, RotateRightByTwo) {
    FixedArray arr(5);
    for (int v : {1, 2, 3, 4, 5}) arr.insert(arr.size(), v);
    arr.rotateRight(2);
    EXPECT_EQ(arr.get(0), 4);
    EXPECT_EQ(arr.get(1), 5);
    EXPECT_EQ(arr.get(2), 1);
    EXPECT_EQ(arr.get(3), 2);
    EXPECT_EQ(arr.get(4), 3);
}

TEST(FixedArrayTest, RotateRightByZeroIsNoOp) {
    FixedArray arr(3);
    for (int v : {1, 2, 3}) arr.insert(arr.size(), v);
    arr.rotateRight(0);
    EXPECT_EQ(arr.get(0), 1);
    EXPECT_EQ(arr.get(1), 2);
    EXPECT_EQ(arr.get(2), 3);
}

TEST(FixedArrayTest, RotateRightByFullSizeIsNoOp) {
    FixedArray arr(3);
    for (int v : {1, 2, 3}) arr.insert(arr.size(), v);
    arr.rotateRight(3);
    EXPECT_EQ(arr.get(0), 1);
}

TEST(FixedArrayTest, RotateRightKLargerThanSize) {
    FixedArray arr(3);
    for (int v : {1, 2, 3}) arr.insert(arr.size(), v);
    arr.rotateRight(4); // 4 % 3 == 1, so equivalent to rotateRight(1)
    EXPECT_EQ(arr.get(0), 3);
    EXPECT_EQ(arr.get(1), 1);
    EXPECT_EQ(arr.get(2), 2);
}
