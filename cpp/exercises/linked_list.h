#pragma once
#include <string>
#include <vector>

/**
 * A singly-linked list of integers.
 *
 * Head insertions are O(1); tail insertions and traversals are O(n).
 * No tail pointer is maintained — this is intentional.
 */
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    /** Append value to the end of the list. O(n). */
    void append(int value);

    /** Insert value at the front of the list. O(1). */
    void prepend(int value);

    /**
     * Delete the first node whose value equals the given value.
     * @return true if a node was removed, false if not found.
     */
    bool deleteValue(int value);

    /**
     * Search the list for value.
     * @return true if found, false otherwise.
     */
    bool find(int value) const;

    /** Reverse the list in-place by rewiring pointers. O(n). */
    void reverse();

    /** Return all values in order from head to tail. */
    std::vector<int> toVector() const;

    /** Return the number of nodes. */
    int size() const;

    /** Return a string like "1 -> 2 -> 3". */
    std::string toString() const;

    // Non-copyable — owns heap-allocated nodes
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

private:
    struct Node {
        int   value;
        Node* next;
        explicit Node(int v) : value(v), next(nullptr) {}
    };

    Node* head_;
    int   size_;
};
