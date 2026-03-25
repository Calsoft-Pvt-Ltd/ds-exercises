package exercises;

import org.junit.jupiter.api.Test;
import java.util.List;
import java.util.NoSuchElementException;
import static org.junit.jupiter.api.Assertions.*;

public class QueueTest {

    // --- Initialization ---

    @Test
    void newQueueIsEmpty() {
        MyQueue q = new MyQueue();
        assertTrue(q.isEmpty());
        assertEquals(0, q.size());
    }

    // --- Enqueue / Dequeue ---

    @Test
    void enqueueIncreasesSize() {
        MyQueue q = new MyQueue();
        q.enqueue(1);
        assertEquals(1, q.size());
    }

    @Test
    void dequeueReturnsFirstEnqueued() {
        MyQueue q = new MyQueue();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        assertEquals(1, q.dequeue());
    }

    @Test
    void fifoOrder() {
        MyQueue q = new MyQueue();
        int[] items = {10, 20, 30, 40};
        for (int item : items) q.enqueue(item);
        int[] result = new int[4];
        for (int i = 0; i < 4; i++) result[i] = (int) q.dequeue();
        assertArrayEquals(new int[]{10, 20, 30, 40}, result);
    }

    @Test
    void dequeueDecreasesSize() {
        MyQueue q = new MyQueue();
        q.enqueue("a");
        q.enqueue("b");
        q.dequeue();
        assertEquals(1, q.size());
    }

    @Test
    void dequeueEmptyThrows() {
        MyQueue q = new MyQueue();
        assertThrows(NoSuchElementException.class, q::dequeue);
    }

    // --- Peek ---

    @Test
    void peekReturnsFront() {
        MyQueue q = new MyQueue();
        q.enqueue("first");
        q.enqueue("second");
        assertEquals("first", q.peek());
    }

    @Test
    void peekDoesNotRemove() {
        MyQueue q = new MyQueue();
        q.enqueue(99);
        q.peek();
        assertEquals(1, q.size());
    }

    @Test
    void peekEmptyThrows() {
        MyQueue q = new MyQueue();
        assertThrows(NoSuchElementException.class, q::peek);
    }

    // --- TaskProcessor ---

    @Test
    void submitIncreasesPending() {
        MyQueue.TaskProcessor tp = new MyQueue.TaskProcessor();
        tp.submitTask("task-1");
        tp.submitTask("task-2");
        assertEquals(2, tp.pendingCount());
    }

    @Test
    void processNextReturnsTask() {
        MyQueue.TaskProcessor tp = new MyQueue.TaskProcessor();
        tp.submitTask("email-job");
        assertEquals("email-job", tp.processNext());
    }

    @Test
    void processNextFifoOrder() {
        MyQueue.TaskProcessor tp = new MyQueue.TaskProcessor();
        tp.submitTask("first");
        tp.submitTask("second");
        tp.submitTask("third");
        assertEquals("first", tp.processNext());
        assertEquals("second", tp.processNext());
    }

    @Test
    void processNextDecreasesPending() {
        MyQueue.TaskProcessor tp = new MyQueue.TaskProcessor();
        tp.submitTask("a");
        tp.submitTask("b");
        tp.processNext();
        assertEquals(1, tp.pendingCount());
    }

    @Test
    void processNextEmptyThrows() {
        MyQueue.TaskProcessor tp = new MyQueue.TaskProcessor();
        assertThrows(NoSuchElementException.class, tp::processNext);
    }

    @Test
    void processAllReturnsAllTasks() {
        MyQueue.TaskProcessor tp = new MyQueue.TaskProcessor();
        tp.submitTask("a");
        tp.submitTask("b");
        tp.submitTask("c");
        assertEquals(List.of("a", "b", "c"), tp.processAll());
    }

    @Test
    void processAllClearsQueue() {
        MyQueue.TaskProcessor tp = new MyQueue.TaskProcessor();
        tp.submitTask("x");
        tp.submitTask("y");
        tp.processAll();
        assertEquals(0, tp.pendingCount());
    }

    @Test
    void processedHistoryAccumulates() {
        MyQueue.TaskProcessor tp = new MyQueue.TaskProcessor();
        tp.submitTask("job-1");
        tp.submitTask("job-2");
        tp.processNext();
        tp.submitTask("job-3");
        tp.processAll();
        assertEquals(List.of("job-1", "job-2", "job-3"), tp.getProcessed());
    }
}
