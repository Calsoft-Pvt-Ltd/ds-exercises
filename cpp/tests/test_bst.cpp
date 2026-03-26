#include <gtest/gtest.h>
#include <vector>
#include "bst.h"

// --- Insert / Inorder ---

TEST(BSTTest, InorderReturnsSortedValues) {
    BST bst;
    for (int v : {5, 3, 7, 1, 4}) bst.insert(v);
    EXPECT_EQ(bst.inorder(), (std::vector<int>{1, 3, 4, 5, 7}));
}

TEST(BSTTest, InorderEmpty) {
    BST bst;
    EXPECT_EQ(bst.inorder(), (std::vector<int>{}));
}

TEST(BSTTest, InorderSingleElement) {
    BST bst;
    bst.insert(42);
    EXPECT_EQ(bst.inorder(), (std::vector<int>{42}));
}

TEST(BSTTest, InsertDuplicateIgnored) {
    BST bst;
    bst.insert(5);
    bst.insert(5);
    EXPECT_EQ(bst.inorder(), (std::vector<int>{5}));
}

// --- Search ---

TEST(BSTTest, SearchHit) {
    BST bst;
    bst.insert(5);
    EXPECT_TRUE(bst.search(5));
}

TEST(BSTTest, SearchMiss) {
    BST bst;
    bst.insert(5);
    EXPECT_FALSE(bst.search(99));
}

TEST(BSTTest, SearchEmptyTree) {
    BST bst;
    EXPECT_FALSE(bst.search(1));
}

// --- Remove ---

TEST(BSTTest, RemoveLeaf) {
    BST bst;
    for (int v : {5, 3, 7}) bst.insert(v);
    EXPECT_TRUE(bst.remove(3));
    EXPECT_FALSE(bst.search(3));
    EXPECT_EQ(bst.inorder(), (std::vector<int>{5, 7}));
}

TEST(BSTTest, RemoveOneChild) {
    BST bst;
    for (int v : {5, 3, 7, 6}) bst.insert(v);
    EXPECT_TRUE(bst.remove(7));
    EXPECT_EQ(bst.inorder(), (std::vector<int>{3, 5, 6}));
}

TEST(BSTTest, RemoveTwoChildren) {
    BST bst;
    for (int v : {5, 3, 7, 6, 8}) bst.insert(v);
    EXPECT_TRUE(bst.remove(7));
    EXPECT_EQ(bst.inorder(), (std::vector<int>{3, 5, 6, 8}));
}

TEST(BSTTest, RemoveRoot) {
    BST bst;
    for (int v : {5, 3, 7}) bst.insert(v);
    EXPECT_TRUE(bst.remove(5));
    EXPECT_FALSE(bst.search(5));
    EXPECT_EQ(bst.inorder(), (std::vector<int>{3, 7}));
}

TEST(BSTTest, RemoveNotFound) {
    BST bst;
    bst.insert(5);
    EXPECT_FALSE(bst.remove(99));
    EXPECT_EQ(bst.inorder(), (std::vector<int>{5}));
}

TEST(BSTTest, InorderSortedAfterRemove) {
    BST bst;
    for (int v : {5, 3, 7, 1, 4, 6, 8}) bst.insert(v);
    bst.remove(3);
    EXPECT_EQ(bst.inorder(), (std::vector<int>{1, 4, 5, 6, 7, 8}));
}

TEST(BSTTest, SearchFalseAfterRemove) {
    BST bst;
    bst.insert(5);
    bst.remove(5);
    EXPECT_FALSE(bst.search(5));
}

TEST(BSTTest, RemoveReinsert) {
    BST bst;
    for (int v : {5, 3, 7}) bst.insert(v);
    bst.remove(3);
    bst.insert(3);
    EXPECT_TRUE(bst.search(3));
    EXPECT_EQ(bst.inorder(), (std::vector<int>{3, 5, 7}));
}

