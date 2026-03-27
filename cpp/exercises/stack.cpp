#include "stack.h"
#include <sstream>
#include <stdexcept>

// ── Stack ───────────────────────────────────────────────────────────────────

Stack::Stack() {}

void Stack::push(int value) {
    // TODO: implement this
    // Add value to the end of items_ (the "top" of the stack)
    items_.push_back(value);
}

int Stack::pop() {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("pop from empty stack")
    if (isEmpty()) {
        throw std::underflow_error("pop from empty stack");
    }

    // 2. Save the back element, remove it from items_ with pop_back(), return it
    int val = items_.back();
    items_.pop_back();
    return val;
}

int Stack::peek() const {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("peek from empty stack")
    if (isEmpty()) {
        throw std::underflow_error("peek from empty stack");
    }

    // 2. Return items_.back() without modifying the stack
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

    Stack local;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            local.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (local.isEmpty()) return false;

            char open = static_cast<char>(local.peek());
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return false;
            }
            local.pop();
        }
    }

    return local.isEmpty();
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