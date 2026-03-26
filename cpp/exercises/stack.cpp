#include "stack.h"
#include <sstream>

Stack::Stack() {}

void Stack::push(int value) {
    // TODO: implement this
    // Add value to the end of items_ (the "top" of the stack)

    // Add value to top (end of vector)
    items_.push_back(value);
}

int Stack::pop() {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("pop from empty stack")
    // 2. Save the back element, remove it from items_ with pop_back(), return it
    // return 0; // placeholder

    // 1. Check empty
    if (items_.empty()) {
        throw std::underflow_error("pop from empty stack");
    }

    // 2. Save and remove top
    int value = items_.back();
    items_.pop_back();

    return value;
}

int Stack::peek() const {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("peek from empty stack")
    // 2. Return items_.back() without modifying the stack
    // return 0; // placeholder

    // 1. Check empty
    if (items_.empty()) {
        throw std::underflow_error("peek from empty stack");
    }

    // 2. Return top element
    return items_.back();
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
    // return false; // placeholder

    Stack st;  // local stack

    for (char c : s) {
        // Opening brackets
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        // Closing brackets
        else if (c == ')' || c == ']' || c == '}') {
            if (st.isEmpty()) {
                return false; // no matching opening
            }

            char top = st.peek();

            // Check matching
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }

            st.pop(); // matched → remove
        }
        // Ignore other characters
    }

    // Final check
    return st.isEmpty();
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
