package exercises;

/**
 * Exercise 1: Fixed-Size Array
 * =============================
 * Arrays have a FIXED capacity allocated upfront. Once full, you cannot add
 * more elements without allocating a new array. This is a fundamental
 * constraint that shapes every decision about when to use them.
 *
 * Java's built-in arrays are already fixed-size, but here you will wrap one
 * to practice the insert/delete/shift logic explicitly.
 *
 * Your task: implement all methods marked with TODO.
 */
public class FixedArray {

    private final Object[] data;
    private final int capacity;
    private int size;

    /**
     * Initialize a fixed-size array with the given capacity.
     * The underlying array is pre-allocated — this models contiguous
     * memory allocation where the space is reserved upfront.
     */
    public FixedArray(int capacity) {
        // TODO: initialize this.data, this.capacity, and this.size
        this.capacity = capacity;
        this.data = new Object[capacity];
        this.size = 0;
    }

    /**
     * Insert {@code value} at position {@code index}.
     *
     * - Shift all elements from {@code index} onward one position to the right.
     * - Place {@code value} at {@code index}.
     * - Increment size.
     *
     * @throws IndexOutOfBoundsException if index < 0 or index > current size
     * @throws IllegalStateException     if the array is already at capacity
     *
     * Think about: why is shifting O(n)? What does this mean for insert-heavy workloads?
     */
    public void insert(int index, Object value) {
        // TODO: implement this
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }

        if (size == capacity) {
            throw new IllegalStateException("Array is full");
        }

        // Shift right
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }

        data[index] = value;
        size++;
    }

    /**
     * Return the value at {@code index}.
     *
     * @throws IndexOutOfBoundsException if index < 0 or index >= current size
     *
     * This is O(1) — the key advantage of arrays over linked lists.
     */
    public Object get(int index) {
        // TODO: implement this
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }

        return data[index];
    }

    /**
     * Delete the element at {@code index}.
     *
     * - Shift all elements after {@code index} one position to the left.
     * - Null out the last occupied slot.
     * - Decrement size.
     *
     * @throws IndexOutOfBoundsException if index < 0 or index >= current size
     */
    public void delete(int index) {
        // TODO: implement this
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }

        // Shift left
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        data[size - 1] = null; // clean up
        size--;
    }

    /**
     * Return the index of the first occurrence of {@code value}.
     * Return -1 if not found.
     *
     * This is O(n) — there is no shortcut without sorting.
     */
    public int find(Object value) {
    for (int i = 0; i < size; i++) {
        if (value == null) {
            if (data[i] == null) return i;
        } else {
            if (value.equals(data[i])) return i;
        }
    }
    return -1;
    }

    /** Return the number of occupied slots (not the capacity). */
    public int size() {
        // TODO: implement this
        return size;
    }

    /**
     * Rotate the occupied elements of the array to the right by {@code k} positions.
     *
     * Example: [1, 2, 3, 4, 5] rotated right by 2 → [4, 5, 1, 2, 3]
     *
     * Only rotate the occupied portion (indices 0 to size-1).
     * k may be larger than size — handle this with modulo arithmetic.
     *
     * Think about: what data structure property makes this an in-place operation?
     */

    private void reverse(int start, int end) {
    while (start < end) {
        Object temp = data[start];
        data[start] = data[end];
        data[end] = temp;
        start++;
        end--;
    }
    }
    public void rotateRight(int k) {
        // TODO: implement this
        if (size == 0) return;

        k = k % size; // handle large k

        reverse(0, size - 1);
        reverse(0, k - 1);
        reverse(k, size - 1);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("FixedArray(capacity=" + capacity + ", elements=[");
        for (int i = 0; i < size; i++) {
            sb.append(data[i]);
            if (i < size - 1) sb.append(", ");
        }
        sb.append("])");
        return sb.toString();
    }
}
