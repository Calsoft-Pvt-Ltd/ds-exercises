#include "fixed_array.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

FixedArray::FixedArray(int capacity)
    : data_(new int[capacity]), capacity_(capacity), size_(0) {}

FixedArray::~FixedArray() {
    delete[] data_;
}

void FixedArray::insert(int index, int value) {
    if (index < 0 || index > size_) {
        throw std::out_of_range("index out of range");
    }

    if (size_ == capacity_) {
        throw std::overflow_error("array is full");
    }

    for (int i = size_ - 1; i >= index; i--) {
        data_[i + 1] = data_[i];
    }

    data_[index] = value;
    size_++;
}

int FixedArray::get(int index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("index out of range");
    }
    return data_[index];
}

void FixedArray::deleteAt(int index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("index out of range");
    }

    for (int i = index; i < size_ - 1; i++) {
        data_[i] = data_[i + 1];
    }

    size_--;
}

int FixedArray::find(int value) const {
    for (int i = 0; i < size_; i++) {
        if (data_[i] == value) {
            return i;
        }
    }
    return -1;
}

int FixedArray::size() const {
    return size_;
}

void FixedArray::rotateRight(int k) {
    if (size_ == 0) return;

    k = k % size_;

    auto reverse = [&](int start, int end) {
        while (start < end) {
            std::swap(data_[start], data_[end]);
            start++;
            end--;
        }
    };

    reverse(0, size_ - 1);
    reverse(0, k - 1);
    reverse(k, size_ - 1);
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