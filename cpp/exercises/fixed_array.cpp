#include "fixed_array.h"
#include <sstream>
#include <algorithm>

FixedArray::FixedArray(int capacity)
    : data_(new int[capacity]), capacity_(capacity), size_(0) {}

FixedArray::~FixedArray() {
    delete[] data_;
}

void FixedArray::insert(int index, int value) {
    // TODO: implement this
    // 1. If index < 0 or index > size_, throw std::out_of_range("index out of range")
    // 2. If size_ == capacity_, throw std::overflow_error("array is full")
    // 3. Shift elements at [index .. size_-1] one position right
    // 4. Set data_[index] = value; increment size_

    // 1. Index validation
    if (index < 0 || index > size_) {
        throw std::out_of_range("index out of range");
    }

    // 2. Capacity check
    if (size_ == capacity_) {
        throw std::overflow_error("array is full");
    }

    // 3. Shift elements to the right
    for (int i = size_ - 1; i >= index; i--) {
        data_[i + 1] = data_[i];
    }

    // 4. Insert value and update size
    data_[index] = value;
    size_++;
}

int FixedArray::get(int index) const {
    // TODO: implement this
    // 1. If index < 0 or index >= size_, throw std::out_of_range("index out of range")
    // 2. Return data_[index]
    // return 0; // placeholder — remove when implemented

     // 1. Index validation
    if (index < 0 || index >= size_) {
        throw std::out_of_range("index out of range");
    }

    // 2. Return value
    return data_[index];
}

void FixedArray::deleteAt(int index) {
    // TODO: implement this
    // 1. If index < 0 or index >= size_, throw std::out_of_range("index out of range")
    // 2. Shift elements at [index+1 .. size_-1] one position left
    // 3. Decrement size_

    // 1. Index validation
    if (index < 0 || index >= size_) {
        throw std::out_of_range("index out of range");
    }

    // 2. Shift elements to the left
    for (int i = index; i < size_ - 1; i++) {
        data_[i] = data_[i + 1];
    }

    // 3. Decrease size
    size_--;
}

int FixedArray::find(int value) const {
    // TODO: implement this
    // Linear scan: return the index of the first element equal to value, or -1
    // return -1; // placeholder — remove when implemented

     // Linear search
    for (int i = 0; i < size_; i++) {
        if (data_[i] == value) {
            return i;  // mil gaya
        }
    }

    return -1;  // nahi mila
}

int FixedArray::size() const {
    return size_;
}

void FixedArray::rotateRight(int k) {
    // TODO: implement this
    // Rotate the occupied region [0 .. size_-1] right by k positions.
    // Hint: use the "three-reverse" trick —
    //   1. Normalise: k = k % size_ (guard against size_==0 first)
    //   2. Reverse the entire occupied region
    //   3. Reverse the first k elements
    //   4. Reverse elements [k .. size_-1]

    // Edge case
    if (size_ == 0) return;

    // Step 1: Normalize k
    k = k % size_;

    // Step 2: Reverse entire array
    std::reverse(data_, data_ + size_);

    // Step 3: Reverse first k elements
    std::reverse(data_, data_ + k);

    // Step 4: Reverse remaining elements
    std::reverse(data_ + k, data_ + size_);
}

std::string FixedArray::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (int i = 0; i < size_; ++i) {
        if (i > 0) oss << ", ";
        oss << data_[i];
    }
    oss << "]";
    return oss.str();
}
