package exercises;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class FixedArrayTest {

    // --- Initialization ---

    @Test
    void initialSizeIsZero() {
        FixedArray a = new FixedArray(5);
        assertEquals(0, a.size());
    }

    @Test
    void capacityIsRespected() {
        FixedArray a = new FixedArray(3);
        a.insert(0, "a");
        a.insert(1, "b");
        a.insert(2, "c");
        assertThrows(IllegalStateException.class, () -> a.insert(0, "d"));
    }

    // --- Insert ---

    @Test
    void insertAtBeginning() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 10);
        assertEquals(10, a.get(0));
        assertEquals(1, a.size());
    }

    @Test
    void insertShiftsElementsRight() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 1);
        a.insert(1, 2);
        a.insert(2, 3);
        a.insert(1, 99);
        assertEquals(1, a.get(0));
        assertEquals(99, a.get(1));
        assertEquals(2, a.get(2));
        assertEquals(3, a.get(3));
    }

    @Test
    void insertOutOfBoundsThrows() {
        FixedArray a = new FixedArray(5);
        assertThrows(IndexOutOfBoundsException.class, () -> a.insert(1, 10));
        assertThrows(IndexOutOfBoundsException.class, () -> a.insert(-1, 10));
    }

    // --- Get ---

    @Test
    void getReturnsCorrectValue() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 42);
        assertEquals(42, a.get(0));
    }

    @Test
    void getOutOfBoundsThrows() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 1);
        assertThrows(IndexOutOfBoundsException.class, () -> a.get(1));
        assertThrows(IndexOutOfBoundsException.class, () -> a.get(-1));
    }

    // --- Delete ---

    @Test
    void deleteReducesSize() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 1);
        a.insert(1, 2);
        a.insert(2, 3);
        a.delete(1);
        assertEquals(2, a.size());
    }

    @Test
    void deleteShiftsElementsLeft() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 1);
        a.insert(1, 2);
        a.insert(2, 3);
        a.delete(0);
        assertEquals(2, a.get(0));
        assertEquals(3, a.get(1));
    }

    @Test
    void deleteOutOfBoundsThrows() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 1);
        assertThrows(IndexOutOfBoundsException.class, () -> a.delete(1));
        assertThrows(IndexOutOfBoundsException.class, () -> a.delete(-1));
    }

    // --- Find ---

    @Test
    void findExistingValue() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 10);
        a.insert(1, 20);
        a.insert(2, 30);
        assertEquals(1, a.find(20));
    }

    @Test
    void findFirstOccurrence() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 5);
        a.insert(1, 5);
        assertEquals(0, a.find(5));
    }

    @Test
    void findMissingValue() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 1);
        assertEquals(-1, a.find(99));
    }

    // --- Rotate Right ---

    @Test
    void rotateRightBasic() {
        FixedArray a = new FixedArray(5);
        for (int i = 0; i < 5; i++) a.insert(i, i + 1);
        a.rotateRight(2);
        assertEquals(4, a.get(0));
        assertEquals(5, a.get(1));
        assertEquals(1, a.get(2));
        assertEquals(2, a.get(3));
        assertEquals(3, a.get(4));
    }

    @Test
    void rotateRightBySizeIsNoop() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 1);
        a.insert(1, 2);
        a.insert(2, 3);
        a.rotateRight(3);
        assertEquals(1, a.get(0));
        assertEquals(2, a.get(1));
        assertEquals(3, a.get(2));
    }

    @Test
    void rotateRightKLargerThanSize() {
        FixedArray a = new FixedArray(5);
        a.insert(0, 1);
        a.insert(1, 2);
        a.insert(2, 3);
        a.rotateRight(4); // equivalent to rotate by 1
        assertEquals(3, a.get(0));
        assertEquals(1, a.get(1));
        assertEquals(2, a.get(2));
    }
}
