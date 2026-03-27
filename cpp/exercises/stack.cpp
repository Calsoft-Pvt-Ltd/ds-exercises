#include "stack.h"
#include <sstream>
#include <stdexcept>

// ── Stack ───────────────────────────────────────────────────────────────────

Stack::Stack() {}

void Stack::push(int value) {
    items_.push_back(value);
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("pop from empty stack");
    }

    int val = items_.back();
    items_.pop_back();
    return val;
}

int Stack::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("peek from empty stack");
    }

    return items_.back();
}

bool Stack::isEmpty() const {
    return items_.empty();
}

int Stack::size() const {
    return static_cast<int>(items_.size());
}


// ── isBalanced (IMPORTANT 🔥) ───────────────────────────────────────────────

bool Stack::isBalanced(const std::string& s) {
    Stack st;

    for (char c : s) {

        // Opening brackets
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }

        // Closing brackets
        else if (c == ')' || c == ']' || c == '}') {

            if (st.isEmpty()) return false;

            char top = st.peek();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }

            st.pop();
        }

        // Ignore non-bracket characters
    }

    return st.isEmpty();
}


// ── toString ───────────────────────────────────────────────────────────────

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