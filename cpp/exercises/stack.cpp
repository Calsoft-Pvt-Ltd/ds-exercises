#include "stack.h"
#include <sstream>

Stack::Stack() {}

void Stack::push(int value) {
    // TODO: implement this
    // Add value to the end of items_ (the "top" of the stack)
}

int Stack::pop() {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("pop from empty stack")
    // 2. Save the back element, remove it from items_ with pop_back(), return it
    return 0; // placeholder
}

int Stack::peek() const {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("peek from empty stack")
    // 2. Return items_.back() without modifying the stack
    return 0; // placeholder
}

bool Stack::isEmpty() const {
    return items_.empty();
}

int Stack::size() const {
    return static_cast<int>(items_.size());
}

bool Stack::isBalanced(const std::string& s) {
    // TODO: implement this using a Stack
    // For each character c in s:
    //   If c is '(', '[', or '{' → push it onto a local Stack
    //   If c is ')', ']', or '}':
    //     - If the local stack is empty → return false (no matching open)
    //     - If stack.peek() does not match c → return false (wrong open bracket)
    //     - Otherwise pop the top
    //   Non-bracket characters are ignored
    // After the loop, return true only if the stack is empty (all opens were closed)
    return false; // placeholder
}

std::string Stack::toString() const {
    std::ostringstream oss;
    oss << "Stack[";
    for (int i = 0; i < static_cast<int>(items_.size()); ++i) {
        if (i > 0) oss << ", ";
        oss << items_[i];
    }
    oss << "] (top→right)";
    return oss.str();
}
