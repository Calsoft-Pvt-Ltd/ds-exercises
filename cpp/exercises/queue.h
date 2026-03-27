#pragma once
#include <stdexcept>
#include <string>
#include <deque>
#include <vector>

/**
 * A FIFO queue of integers backed by std::deque.
 */
class Queue {
public:
    Queue();

    /** Add value to the back of the queue. */
    void enqueue(int value);

    /**
     * Remove and return the front element.
     * @throws std::underflow_error if the queue is empty.
     */
    int dequeue();

    /**
     * Return the front element without removing it.
     * @throws std::underflow_error if the queue is empty.
     */
    int peek() const;

    /** Return true if the queue is empty. */
    bool isEmpty() const;

    /** Return the number of elements in the queue. */
    int size() const;

    /** Return a string like "Queue[1, 2, 3] (front→left)". */
    std::string toString() const;

private:
    std::deque<int> items_;
};

/**
 * A task processor that queues and processes string tasks in FIFO order.
 *
 * Models a simple producer–consumer: tasks are submitted, then processed one
 * at a time. Processed tasks are recorded in history.
 */
class TaskProcessor {
public:
    TaskProcessor();

    /** Add a task to the back of the pending queue. */
    void submitTask(const std::string& task);

    /**
     * Process (dequeue and record) the next pending task.
     * @throws std::runtime_error("no pending tasks") if there is nothing to process.
     * @return the task string that was just processed.
     */
    std::string processNext();

    /** Process all pending tasks in FIFO order. */
    void processAll();

    /** Return the number of tasks still pending. */
    int pendingCount() const;

    /** Return all processed tasks in the order they were processed. */
    std::vector<std::string> getProcessed() const;

private:
    std::deque<std::string>  pending_;
    std::vector<std::string> processed_;
};
