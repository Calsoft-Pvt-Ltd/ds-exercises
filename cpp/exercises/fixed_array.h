#pragma once
#include <stdexcept>
#include <string>

/**
 * A fixed-capacity array of integers.
 *
 * Elements are stored contiguously. Insertion and deletion shift neighbours.
 * Random access is O(1); insertion and deletion are O(n).
 */
class FixedArray {
public:
    /**
     * Construct a FixedArray with the given maximum capacity.
     * @param capacity Maximum number of elements this array can hold.
     */
    explicit FixedArray(int capacity);
    ~FixedArray();

    /**
     * Insert value at index, shifting existing elements one position right.
     * @throws std::out_of_range   if index < 0 or index > size()
     * @throws std::overflow_error if the array is already at capacity
     */
    void insert(int index, int value);

    /**
     * Return the element at index.
     * @throws std::out_of_range if index < 0 or index >= size()
     */
    int get(int index) const;

    /**
     * Delete the element at index, shifting remaining elements left.
     * @throws std::out_of_range if index < 0 or index >= size()
     */
    void deleteAt(int index);

    /**
     * Return the index of the first occurrence of value, or -1 if not found.
     */
    int find(int value) const;

    /** Return the number of elements currently stored. */
    int size() const;

    /**
     * Rotate the occupied portion right by k positions.
     * Example: [1,2,3,4,5] rotateRight(2) → [4,5,1,2,3]
     * Handles k=0 and k >= size() gracefully (k is taken modulo size()).
     */
    void rotateRight(int k);

    /** Return a string representation, e.g. "[1, 2, 3]". */
    std::string toString() const;

    // Non-copyable — owns heap memory (Rule of Three)
    FixedArray(const FixedArray&) = delete;
    FixedArray& operator=(const FixedArray&) = delete;

private:
    int* data_;
    int  capacity_;
    int  size_;
};
