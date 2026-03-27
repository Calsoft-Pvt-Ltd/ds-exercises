#include "queue.h"
#include <sstream>
#include <stdexcept>

// ── Queue ────────────────────────────────────────────────────────────────────

Queue::Queue() {}

void Queue::enqueue(int value) {
    items_.push_back(value);
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("dequeue from empty queue");
    }

    int val = items_.front();
    items_.pop_front();
    return val;
}

int Queue::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("peek from empty queue");
    }

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
    pending_.push_back(task);
}

std::string TaskProcessor::processNext() {
    if (pending_.empty()) {
        throw std::runtime_error("no pending tasks");
    }

    std::string task = pending_.front();
    pending_.pop_front();

    processed_.push_back(task);

    return task;
}

void TaskProcessor::processAll() {
    while (pendingCount() > 0) {
        processNext();
    }
}

int TaskProcessor::pendingCount() const {
    return static_cast<int>(pending_.size());
}

std::vector<std::string> TaskProcessor::getProcessed() const {
    return processed_;
}