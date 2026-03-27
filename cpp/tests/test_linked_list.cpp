#include <gtest/gtest.h>
#include "linked_list.h"

// --- Initialization ---

TEST(LinkedListTest, InitialSizeIsZero) {
    LinkedList list;
    EXPECT_EQ(list.size(), 0);
    EXPECT_EQ(list.toVector(), (std::vector<int>{}));
}

// --- Append ---

TEST(LinkedListTest, AppendSingleElement) {
    LinkedList list;
    list.append(1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.toVector(), (std::vector<int>{1}));
}

TEST(LinkedListTest, AppendMaintainsOrder) {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    EXPECT_EQ(list.toVector(), (std::vector<int>{1, 2, 3}));
}

// --- Prepend ---

TEST(LinkedListTest, PrependAddsToFront) {
    LinkedList list;
    list.append(2);
    list.prepend(1);
    EXPECT_EQ(list.toVector(), (std::vector<int>{1, 2}));
}

TEST(LinkedListTest, PrependOnEmptyList) {
    LinkedList list;
    list.prepend(5);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.toVector(), (std::vector<int>{5}));
}

// --- Delete ---

TEST(LinkedListTest, DeleteMiddleNode) {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    EXPECT_TRUE(list.deleteValue(2));
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.toVector(), (std::vector<int>{1, 3}));
}

TEST(LinkedListTest, DeleteHeadNode) {
    LinkedList list;
    list.append(1);
    list.append(2);
    EXPECT_TRUE(list.deleteValue(1));
    EXPECT_EQ(list.toVector(), (std::vector<int>{2}));
}

TEST(LinkedListTest, DeleteTailNode) {
    LinkedList list;
    list.append(1);
    list.append(2);
    EXPECT_TRUE(list.deleteValue(2));
    EXPECT_EQ(list.toVector(), (std::vector<int>{1}));
}

TEST(LinkedListTest, DeleteValueReturnsFalseWhenNotFound) {
    LinkedList list;
    list.append(1);
    EXPECT_FALSE(list.deleteValue(99));
    EXPECT_EQ(list.size(), 1);
}

TEST(LinkedListTest, DeleteOnEmptyListReturnsFalse) {
    LinkedList list;
    EXPECT_FALSE(list.deleteValue(1));
}

TEST(LinkedListTest, DeleteOnlyFirstOccurrence) {
    LinkedList list;
    list.append(1); list.append(2); list.append(2); list.append(3);
    EXPECT_TRUE(list.deleteValue(2));
    EXPECT_EQ(list.toVector(), (std::vector<int>{1, 2, 3}));
}

// --- Find ---

TEST(LinkedListTest, FindReturnsTrueWhenPresent) {
    LinkedList list;
    list.append(5);
    EXPECT_TRUE(list.find(5));
}

TEST(LinkedListTest, FindReturnsFalseWhenAbsent) {
    LinkedList list;
    list.append(1);
    EXPECT_FALSE(list.find(42));
}

TEST(LinkedListTest, FindOnEmptyListReturnsFalse) {
    LinkedList list;
    EXPECT_FALSE(list.find(1));
}

// --- Reverse ---

TEST(LinkedListTest, ReverseMultipleElements) {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.reverse();
    EXPECT_EQ(list.toVector(), (std::vector<int>{3, 2, 1}));
}

TEST(LinkedListTest, ReverseSingleElement) {
    LinkedList list;
    list.append(1);
    list.reverse();
    EXPECT_EQ(list.toVector(), (std::vector<int>{1}));
}

TEST(LinkedListTest, ReverseEmptyListIsNoOp) {
    LinkedList list;
    list.reverse();
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedListTest, ReverseTwiceRestoresOriginal) {
    LinkedList list;
    list.append(1); list.append(2); list.append(3);
    list.reverse();
    list.reverse();
    EXPECT_EQ(list.toVector(), (std::vector<int>{1, 2, 3}));
}
