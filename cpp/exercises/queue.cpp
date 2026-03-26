#include "queue.h"
#include <sstream>

// ── Queue ────────────────────────────────────────────────────────────────────

Queue::Queue() {}

void Queue::enqueue(int value) {
    // TODO: implement this
    // Add value to the back of items_ using push_back()

     // Add value to the back
    items_.push_back(value);
}

int Queue::dequeue() {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("dequeue from empty queue")
    // 2. Save items_.front(), call items_.pop_front() to remove it, return the saved value
    // return 0; // placeholder

     // 1. Check empty
    if (items_.empty()) {
        throw std::underflow_error("dequeue from empty queue");
    }

    // 2. Save front and remove
    int value = items_.front();
    items_.pop_front();

    return value;
}

int Queue::peek() const {
    // TODO: implement this
    // 1. If isEmpty(), throw std::underflow_error("peek from empty queue")
    // 2. Return items_.front() without removing it
    // return 0; // placeholder

    // 1. Check empty
    if (items_.empty()) {
        throw std::underflow_error("peek from empty queue");
    }

    // 2. Return front (no remove)
    return items_.front();
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

    // Add task to pending queue
    pending_.push_back(task);
}

std::string TaskProcessor::processNext() {
    // TODO: implement this
    // 1. If pending_ is empty, throw std::runtime_error("no pending tasks")
    // 2. Save pending_.front(), call pending_.pop_front() to remove it
    // 3. Add the saved task to processed_ using push_back()
    // 4. Return the saved task
    // return ""; // placeholder

     // 1. Check if empty
    if (pending_.empty()) {
        throw std::runtime_error("no pending tasks");
    }

    // 2. Get and remove front task
    std::string task = pending_.front();
    pending_.pop_front();

    // 3. Add to processed list
    processed_.push_back(task);

    // 4. Return task
    return task;
}

void TaskProcessor::processAll() {
    // TODO: implement this
    // Call processNext() in a loop until pendingCount() == 0

    // Process until no tasks left
    while (!pending_.empty()) {
        processNext();
    }
}

int TaskProcessor::pendingCount() const {
    return static_cast<int>(pending_.size());
}

std::vector<std::string> TaskProcessor::getProcessed() const {
    return processed_;
}
