class FixedArray:
    def __init__(self, capacity):
        self._capacity = capacity
        self._data = [None] * capacity
        self._size = 0

    def insert(self, index, value):
        if self._size == self._capacity:
            raise OverflowError("Array is at full capacity")
        if index < 0 or index > self._size:
            raise IndexError("Index out of bounds")
        for i in range(self._size, index, -1):
            self._data[i] = self._data[i - 1]
        self._data[index] = value
        self._size += 1

    def get(self, index):
        if index < 0 or index >= self._size:
            raise IndexError("Index out of bounds")
        return self._data[index]

    def delete(self, index):
        if index < 0 or index >= self._size:
            raise IndexError("Index out of bounds")
        for i in range(index, self._size - 1):
            self._data[i] = self._data[i + 1]
        self._data[self._size - 1] = None
        self._size -= 1

    def find(self, value):
        for i in range(self._size):
            if self._data[i] == value:
                return i
        return -1

    def size(self):
        return self._size

    def rotate_right(self, k):
        if self._size <= 1:
            return
        k = k % self._size
        if k == 0:
            return
        def reverse(l, r):
            while l < r:
                self._data[l], self._data[r] = self._data[r], self._data[l]
                l += 1
                r -= 1
        reverse(0, self._size - 1)
        reverse(0, k - 1)
        reverse(k, self._size - 1)

    def __repr__(self):
        occupied = [self._data[i] for i in range(self._size)]
        return "FixedArray(capacity={}, elements={})".format(self._capacity, occupied)