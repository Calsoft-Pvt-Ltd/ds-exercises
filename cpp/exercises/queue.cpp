#include "queue.h"
#include <sstream>

// ── Queue ────────────────────────────────────────────────────────────────────

Queue::Queue() {}

void Queue::enqueue(int value) {
    // TODO: implement this
    // Add value to the back of items_ using push_back()
}

int Queue::dequeue() {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("dequeue from empty queue")
    // 2. Save items_.front(), call items_.pop_front() to remove it, return the saved value
    return 0; // placeholder
}

int Queue::peek() const {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("peek from empty queue")
    // 2. Return items_.front() without removing it
    return 0; // placeholder
}

bool Queue::isEmpty() const {
    return items_.empty();
}

int Queue::size() const {
    return static_cast<int>(items_.size());
}

std::string Queue::toString() const {
    std::ostringstream oss;
    oss << "Queue[";
    bool first = true;
    for (int v : items_) {
        if (!first) oss << ", ";
        oss << v;
        first = false;
    }
    oss << "] (front→left)";
    return oss.str();
}

// ── TaskProcessor ─────────────────────────────────────────────────────────────

TaskProcessor::TaskProcessor() {}

void TaskProcessor::submitTask(const std::string& task) {
    // TODO: implement this
    // Add task to the back of pending_ using push_back()
}

std::string TaskProcessor::processNext() {
    // TODO: implement this
    // 1. If pending_ is empty, throw std::runtime_error("no pending tasks")
    // 2. Save pending_.front(), call pending_.pop_front() to remove it
    // 3. Add the saved task to processed_ using push_back()
    // 4. Return the saved task
    return ""; // placeholder
}

void TaskProcessor::processAll() {
    // TODO: implement this
    // Call processNext() in a loop until pendingCount() == 0
}

int TaskProcessor::pendingCount() const {
    return static_cast<int>(pending_.size());
}

std::vector<std::string> TaskProcessor::getProcessed() const {
    return processed_;
}
