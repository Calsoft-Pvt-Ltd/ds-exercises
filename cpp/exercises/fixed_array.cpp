#include "fixed_array.h"
#include <sstream>

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

    if(index<0 || index>size_){
        throw std::out_of_range("index out of range");
    }
    if(size_ == capacity_){
        throw std::overflow_error("array is full");
    }

    for(int i=size_-1; i>=index; i--){
        data_[i+1] = data_[i];
    }
    data_[index] = value;
    size_++;


}

int FixedArray::get(int index) const {
    // TODO: implement this
    // 1. If index < 0 or index >= size_, throw std::out_of_range("index out of range")
    // 2. Return data_[index]
    if(index<0 || index>=size_){
        throw std::out_of_range("index out of range");
    }
    return data_[index];
}

void FixedArray::deleteAt(int index) {
    // TODO: implement this
    // 1. If index < 0 or index >= size_, throw std::out_of_range("index out of range")
    // 2. Shift elements at [index+1 .. size_-1] one position left
    // 3. Decrement size_
    if(index<0 || index>=size_){
        throw std::out_of_range("index out of range");
    }
    for(int i=index; i<size_-1; i++){
        data_[i] = data_[i+1];
    }
    size_--;

}

int FixedArray::find(int value) const {
    // TODO: implement this
    // Linear scan: return the index of the first element equal to value, or -1

    for(int i=0; i<size_; i++){
        if(data_[i] == value){
            return i;
        }
    }

    return -1; // placeholder — remove when implemented



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

    if(size_ == 0) return; 
    k = k % size_;

    for(int i=0; i<size_/2; i++){
        std::swap(data_[i], data_[size_-1-i]);
    }

    for(int i=0; i<k/2; i++){
        std::swap(data_[i], data_[k-1-i]);
    }

    for(int i=k; i<(k+size_)/2; i++){
        std::swap(data_[i], data_[size_-1-(i-k)]);
    }


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
