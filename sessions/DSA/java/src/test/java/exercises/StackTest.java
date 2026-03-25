package exercises;

import org.junit.jupiter.api.Test;
import java.util.EmptyStackException;
import static org.junit.jupiter.api.Assertions.*;

public class StackTest {

    // --- Initialization ---

    @Test
    void newStackIsEmpty() {
        MyStack s = new MyStack();
        assertTrue(s.isEmpty());
        assertEquals(0, s.size());
    }

    // --- Push / Pop ---

    @Test
    void pushIncreasesSize() {
        MyStack s = new MyStack();
        s.push(1);
        assertEquals(1, s.size());
        s.push(2);
        assertEquals(2, s.size());
    }

    @Test
    void popReturnsLastPushed() {
        MyStack s = new MyStack();
        s.push(1);
        s.push(2);
        s.push(3);
        assertEquals(3, s.pop());
        assertEquals(2, s.pop());
        assertEquals(1, s.pop());
    }

    @Test
    void popDecreasesSize() {
        MyStack s = new MyStack();
        s.push(10);
        s.push(20);
        s.pop();
        assertEquals(1, s.size());
    }

    @Test
    void popEmptyThrows() {
        MyStack s = new MyStack();
        assertThrows(EmptyStackException.class, s::pop);
    }

    @Test
    void lifoOrder() {
        MyStack s = new MyStack();
        int[] items = {1, 2, 3, 4, 5};
        for (int item : items) s.push(item);
        int[] result = new int[5];
        for (int i = 0; i < 5; i++) result[i] = (int) s.pop();
        assertArrayEquals(new int[]{5, 4, 3, 2, 1}, result);
    }

    // --- Peek ---

    @Test
    void peekReturnsTop() {
        MyStack s = new MyStack();
        s.push(7);
        s.push(8);
        assertEquals(8, s.peek());
    }

    @Test
    void peekDoesNotRemove() {
        MyStack s = new MyStack();
        s.push(42);
        s.peek();
        assertEquals(1, s.size());
        assertEquals(42, s.peek());
    }

    @Test
    void peekEmptyThrows() {
        MyStack s = new MyStack();
        assertThrows(EmptyStackException.class, s::peek);
    }

    // --- isBalanced ---

    @Test
    void balancedSimpleParens() {
        assertTrue(MyStack.isBalanced("()"));
    }

    @Test
    void balancedNested() {
        assertTrue(MyStack.isBalanced("({[]})"));
    }

    @Test
    void balancedWithOtherChars() {
        assertTrue(MyStack.isBalanced("hello(world[!])"));
    }

    @Test
    void balancedEmptyString() {
        assertTrue(MyStack.isBalanced(""));
    }

    @Test
    void unbalancedWrongOrder() {
        assertFalse(MyStack.isBalanced("({[})"));
    }

    @Test
    void unbalancedUnclosed() {
        assertFalse(MyStack.isBalanced("((("));
    }

    @Test
    void unbalancedExtraClose() {
        assertFalse(MyStack.isBalanced("))"));
    }

    @Test
    void unbalancedCloseBeforeOpen() {
        assertFalse(MyStack.isBalanced(")()"));
    }

    @Test
    void balancedMultiplePairs() {
        assertTrue(MyStack.isBalanced("()[]{}"));
    }

    @Test
    void unbalancedMismatched() {
        assertFalse(MyStack.isBalanced("(]"));
    }
}
