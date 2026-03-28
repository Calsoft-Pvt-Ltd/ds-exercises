"""
Exercise 1: Fixed-Size Array
============================
Arrays have a FIXED capacity allocated upfront. Once full, you cannot add more
elements without allocating a new array. This is a fundamental constraint that
shapes every decision about when to use them.

In Python, lists resize automatically — so here you will simulate a true
fixed-size array to feel that constraint directly.

Your task: implement all methods marked with TODO.
"""


class FixedArray:
    def __init__(self, capacity: int):
        """
        Initialize a fixed-size array.

        - Allocate a list of `capacity` slots, each pre-filled with None.
        - Store the capacity.
        - Track the current number of occupied slots.

        This models contiguous memory allocation: the space is reserved upfront.
        """
        # TODO: implement this
        self._capacity = capacity
        self._data = [None] * capacity
        self._size = 0

    def insert(self, index: int, value) -> None:
        """
        Insert `value` at position `index`.

        - Shift all elements from `index` onward one position to the right.
        - Place `value` at `index`.
        - Increment size.

        Raise IndexError if `index` is out of bounds (< 0 or > current size).
        Raise OverflowError if the array is already at capacity.

        Think about: why is shifting O(n)? What does this mean for insert-heavy workloads?
        """
        # TODO: implement this
        if index < 0 or index > self._size:
            raise IndexError("Index out of bounds")

        if self._size == self._capacity:
            raise OverflowError("Array is full")

        # Shift elements right
        for i in range(self._size, index, -1):
            self._data[i] = self._data[i - 1]

        self._data[index] = value
        self._size += 1

    def get(self, index: int):
        """
        Return the value at `index`.

        Raise IndexError if `index` is out of bounds (< 0 or >= current size).

        This is O(1) — the key advantage of arrays over linked lists.
        """
        # TODO: implement this
        if index < 0 or index >= self._size:
            raise IndexError("Index out of bounds")

        return self._data[index]

    def delete(self, index: int) -> None:
        """
        Delete the element at `index`.

        - Shift all elements after `index` one position to the left.
        - Set the last occupied slot to None.
        - Decrement size.

        Raise IndexError if `index` is out of bounds.
        """
        # TODO: implement this
        if index < 0 or index >= self._size:
            raise IndexError("Index out of bounds")

        # Shift elements left
        for i in range(index, self._size - 1):
            self._data[i] = self._data[i + 1]

        # Clear last element
        self._data[self._size - 1] = None
        self._size -= 1

    def find(self, value) -> int:
        """
        Return the index of the first occurrence of `value`.
        Return -1 if not found.

        This is O(n) — there is no shortcut without sorting.
        """
        # TODO: implement this
        for i in range(self._size):
            if self._data[i] == value:
                return i
        return -1

    def size(self) -> int:
        """Return the number of occupied slots (not the capacity)."""
        # TODO: implement this
        return self._size

    def rotate_right(self, k: int) -> None:
        """
        Rotate the occupied elements of the array to the right by `k` positions.

        Example: [1, 2, 3, 4, 5] rotated right by 2 → [4, 5, 1, 2, 3]

        Only rotate the occupied portion (indices 0 to size-1).
        k may be larger than size — handle this with modulo arithmetic.

        Think about: what data structure property makes this an in-place operation?
        """
        # TODO: implement this
        if self._size == 0:
            return

        k = k % self._size
        if k == 0:
            return

        # Rotate using slicing logic (manual since fixed array)
        temp = self._data[self._size - k:self._size]

        # Shift remaining elements right
        for i in range(self._size - k - 1, -1, -1):
            self._data[i + k] = self._data[i]

        # Place temp elements at front
        for i in range(k):
            self._data[i] = temp[i]

    def __repr__(self) -> str:
        occupied = [self._data[i] for i in range(self._size)]
        return f"FixedArray(capacity={self._capacity}, elements={occupied})"
