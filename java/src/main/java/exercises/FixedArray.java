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
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException();
        }
        if (size == capacity) {
            throw new IllegalStateException("Array is at full capacity");
        }
 
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
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
 
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
 
        data[size - 1] = null;
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
            if (value == null ? data[i] == null : value.equals(data[i])) {
                return i;
            }
        }
        return -1;
    }
 
    /** Return the number of occupied slots (not the capacity). */
    public int size() {
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
    public void rotateRight(int k) {
        if (size == 0) return;
 
        k = k % size;
        if (k == 0) return;
 
        reverse(0, size - 1);
        reverse(0, k - 1);
        reverse(k, size - 1);
    }
 
    private void reverse(int left, int right) {
        while (left < right) {
            Object temp = data[left];
            data[left] = data[right];
            data[right] = temp;
            left++;
            right--;
        }
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
 
    // ✅ Main method added ONLY for manual testing / demo
    public static void main(String[] args) {
        FixedArray arr = new FixedArray(5);
 
        arr.insert(0, 1);
        arr.insert(1, 2);
        arr.insert(2, 3);
        arr.insert(1, 99);
 
        System.out.println(arr);
 
        arr.delete(2);
        System.out.println("After delete: " + arr);
 
        arr.rotateRight(1);
        System.out.println("After rotateRight(1): " + arr);
 
        System.out.println("Index of 99: " + arr.find(99));
        System.out.println("Current size: " + arr.size());
    }
}
 
 
