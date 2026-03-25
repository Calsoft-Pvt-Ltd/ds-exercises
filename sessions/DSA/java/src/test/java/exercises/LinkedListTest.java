package exercises;

import org.junit.jupiter.api.Test;
import java.util.List;
import static org.junit.jupiter.api.Assertions.*;

public class LinkedListTest {

    // --- Initialization ---

    @Test
    void emptyListSize() {
        MyLinkedList ll = new MyLinkedList();
        assertEquals(0, ll.size());
    }

    @Test
    void emptyToList() {
        MyLinkedList ll = new MyLinkedList();
        assertTrue(ll.toList().isEmpty());
    }

    // --- Append ---

    @Test
    void appendSingle() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(1);
        assertEquals(List.of(1), ll.toList());
        assertEquals(1, ll.size());
    }

    @Test
    void appendMultiple() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(1);
        ll.append(2);
        ll.append(3);
        assertEquals(List.of(1, 2, 3), ll.toList());
    }

    // --- Prepend ---

    @Test
    void prependSingle() {
        MyLinkedList ll = new MyLinkedList();
        ll.prepend(1);
        assertEquals(List.of(1), ll.toList());
    }

    @Test
    void prependMultiple() {
        MyLinkedList ll = new MyLinkedList();
        ll.prepend(3);
        ll.prepend(2);
        ll.prepend(1);
        assertEquals(List.of(1, 2, 3), ll.toList());
    }

    @Test
    void prependToNonEmpty() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(2);
        ll.append(3);
        ll.prepend(1);
        assertEquals(List.of(1, 2, 3), ll.toList());
    }

    // --- Delete ---

    @Test
    void deleteHead() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(1); ll.append(2); ll.append(3);
        assertTrue(ll.delete(1));
        assertEquals(List.of(2, 3), ll.toList());
    }

    @Test
    void deleteTail() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(1); ll.append(2); ll.append(3);
        ll.delete(3);
        assertEquals(List.of(1, 2), ll.toList());
    }

    @Test
    void deleteMiddle() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(1); ll.append(2); ll.append(3);
        ll.delete(2);
        assertEquals(List.of(1, 3), ll.toList());
    }

    @Test
    void deleteNonexistentReturnsFalse() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(1);
        assertFalse(ll.delete(99));
    }

    @Test
    void deleteFromEmpty() {
        MyLinkedList ll = new MyLinkedList();
        assertFalse(ll.delete(1));
    }

    @Test
    void deleteOnlyFirstOccurrence() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(1); ll.append(2); ll.append(2); ll.append(3);
        ll.delete(2);
        assertEquals(List.of(1, 2, 3), ll.toList());
    }

    // --- Find ---

    @Test
    void findExisting() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(1); ll.append(2); ll.append(3);
        assertTrue(ll.find(2));
    }

    @Test
    void findMissing() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(1);
        assertFalse(ll.find(99));
    }

    @Test
    void findEmpty() {
        MyLinkedList ll = new MyLinkedList();
        assertFalse(ll.find(1));
    }

    // --- Reverse ---

    @Test
    void reverseMultiple() {
        MyLinkedList ll = new MyLinkedList();
        for (int v : new int[]{1, 2, 3, 4, 5}) ll.append(v);
        ll.reverse();
        assertEquals(List.of(5, 4, 3, 2, 1), ll.toList());
    }

    @Test
    void reverseSingle() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(42);
        ll.reverse();
        assertEquals(List.of(42), ll.toList());
    }

    @Test
    void reverseEmpty() {
        MyLinkedList ll = new MyLinkedList();
        ll.reverse();
        assertTrue(ll.toList().isEmpty());
    }

    @Test
    void reverseTwiceRestoresOriginal() {
        MyLinkedList ll = new MyLinkedList();
        ll.append(1); ll.append(2); ll.append(3);
        ll.reverse();
        ll.reverse();
        assertEquals(List.of(1, 2, 3), ll.toList());
    }
}
