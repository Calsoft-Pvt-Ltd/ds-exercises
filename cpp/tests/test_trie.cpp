#include <gtest/gtest.h>
#include "trie.h"

// --- Insert / Search ---

TEST(TrieTest, InsertThenSearch) {
    Trie t;
    t.insert("hello");
    EXPECT_TRUE(t.search("hello"));
}

TEST(TrieTest, SearchMissingWord) {
    Trie t;
    t.insert("hello");
    EXPECT_FALSE(t.search("world"));
}

TEST(TrieTest, SearchEmptyTrie) {
    Trie t;
    EXPECT_FALSE(t.search("hello"));
}

// --- startsWith ---

TEST(TrieTest, StartsWithValidPrefix) {
    Trie t;
    t.insert("apple");
    EXPECT_TRUE(t.startsWith("app"));
}

TEST(TrieTest, StartsWithInvalidPrefix) {
    Trie t;
    t.insert("apple");
    EXPECT_FALSE(t.startsWith("xyz"));
}

TEST(TrieTest, StartsWithFullWord) {
    Trie t;
    t.insert("apple");
    EXPECT_TRUE(t.startsWith("apple"));
}

// --- Shared prefix ---

TEST(TrieTest, SharedPrefixSearchLonger) {
    Trie t;
    t.insert("apple");
    t.insert("app");
    EXPECT_TRUE(t.search("apple"));
}

TEST(TrieTest, SharedPrefixSearchShorter) {
    Trie t;
    t.insert("apple");
    t.insert("app");
    EXPECT_TRUE(t.search("app"));
}

TEST(TrieTest, SharedPrefixSearchPartialOnly) {
    Trie t;
    t.insert("apple");
    t.insert("app");
    EXPECT_FALSE(t.search("ap"));
}

// --- Duplicate insert ---

TEST(TrieTest, InsertDuplicateNoChange) {
    Trie t;
    t.insert("hello");
    t.insert("hello");
    EXPECT_TRUE(t.search("hello"));
}

// --- Empty string ---

TEST(TrieTest, InsertEmptyStringThenSearch) {
    Trie t;
    t.insert("");
    EXPECT_TRUE(t.search(""));
}

TEST(TrieTest, StartsWithEmptyPrefixNonEmptyTrie) {
    Trie t;
    t.insert("hello");
    EXPECT_TRUE(t.startsWith(""));
}

TEST(TrieTest, SearchEmptyStringOnEmptyTrie) {
    Trie t;
    EXPECT_FALSE(t.search(""));
}
