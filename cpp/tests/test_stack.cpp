#include <gtest/gtest.h>
#include "stack.h"

// --- Initialization ---

TEST(StackTest, InitiallyEmpty) {
    Stack s;
    EXPECT_TRUE(s.isEmpty());
    EXPECT_EQ(s.size(), 0);
}

// --- Push ---

TEST(StackTest, PushIncreasesSize) {
    Stack s;
    s.push(1);
    EXPECT_EQ(s.size(), 1);
    EXPECT_FALSE(s.isEmpty());
}

// --- Peek ---

TEST(StackTest, PeekReturnsTopWithoutRemoving) {
    Stack s;
    s.push(1);
    s.push(2);
    EXPECT_EQ(s.peek(), 2);
    EXPECT_EQ(s.size(), 2);
}

TEST(StackTest, PeekThrowsWhenEmpty) {
    Stack s;
    EXPECT_THROW(s.peek(), std::underflow_error);
}

// --- Pop ---

TEST(StackTest, PopReturnsTopAndRemoves) {
    Stack s;
    s.push(1);
    s.push(2);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.size(), 1);
}

TEST(StackTest, PopThrowsWhenEmpty) {
    Stack s;
    EXPECT_THROW(s.pop(), std::underflow_error);
}

TEST(StackTest, LIFOOrdering) {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    EXPECT_EQ(s.pop(), 3);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 1);
    EXPECT_TRUE(s.isEmpty());
}

// --- isBalanced ---

TEST(StackTest, IsBalancedEmptyStringIsTrue) {
    EXPECT_TRUE(Stack::isBalanced(""));
}

TEST(StackTest, IsBalancedSimpleParen) {
    EXPECT_TRUE(Stack::isBalanced("()"));
}

TEST(StackTest, IsBalancedNestedMixed) {
    EXPECT_TRUE(Stack::isBalanced("({[]})"));
}

TEST(StackTest, IsBalancedSequential) {
    EXPECT_TRUE(Stack::isBalanced("()[]{}"));
}

TEST(StackTest, IsBalancedMismatchedParen) {
    EXPECT_FALSE(Stack::isBalanced("(]"));
}

TEST(StackTest, IsBalancedWrongOrder) {
    EXPECT_FALSE(Stack::isBalanced("({)}"));
}

TEST(StackTest, IsBalancedUnclosedOpen) {
    EXPECT_FALSE(Stack::isBalanced("("));
}

TEST(StackTest, IsBalancedExtraClosing) {
    EXPECT_FALSE(Stack::isBalanced(")"));
    EXPECT_FALSE(Stack::isBalanced("())"));
}

TEST(StackTest, IsBalancedIgnoresNonBracketChars) {
    EXPECT_TRUE(Stack::isBalanced("hello(world[!])"));
    EXPECT_TRUE(Stack::isBalanced("int main() { return 0; }"));
}
