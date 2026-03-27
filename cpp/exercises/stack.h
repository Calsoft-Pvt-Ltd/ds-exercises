#pragma once
#include <stdexcept>
#include <string>
#include <vector>

/**
 * A LIFO stack of integers backed by std::vector.
 */
class Stack {
public:
    Stack();

    /** Push value onto the top. */
    void push(int value);

    /**
     * Remove and return the top element.
     * @throws std::underflow_error if the stack is empty.
     */
    int pop();

    /**
     * Return the top element without removing it.
     * @throws std::underflow_error if the stack is empty.
     */
    int peek() const;

    /** Return true if the stack contains no elements. */
    bool isEmpty() const;

    /** Return the number of elements in the stack. */
    int size() const;

    /**
     * Return true if every opening bracket in s has a matching closing bracket
     * in the correct order. Valid pairs: (), [], {}
     * Non-bracket characters are ignored.
     *
     * Examples:
     *   "({[]})"              → true
     *   "({)}"                → false
     *   ""                    → true
     *   "hello(world[!])"     → true
     */
    static bool isBalanced(const std::string& s);

    /** Return a string like "Stack[1, 2, 3] (top→right)". */
    std::string toString() const;

private:
    std::vector<int> items_;
};
