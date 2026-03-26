package exercises;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

/**
 * Exercise 4: Queue (FIFO) + Task Processor
 * ===========================================
 * A queue is a First-In, First-Out (FIFO) structure. The first element
 * enqueued is the first element dequeued. Think of a line at a coffee shop.
 *
 * Real-world examples:
 *   - Message queues (RabbitMQ, SQS): tasks enqueued by producers,
 *     processed by consumers.
 *   - HTTP request pipelines: requests handled in the order they arrive.
 *   - OS process scheduling: processes wait in a queue for CPU time.
 *
 * Your task: implement all methods marked with TODO in both classes.
 */
public class MyQueue {

    private final ArrayDeque<Object> items;

    /**
     * Initialize an empty queue.
     *
     * Use Java's ArrayDeque as internal storage.
     * ArrayDeque provides O(1) addLast (enqueue) and O(1) pollFirst (dequeue).
     * A plain ArrayList would give O(n) for dequeue — think about why.
     */
    public MyQueue() {
        // TODO: initialize items
        items = new ArrayDeque<>();
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /** Add {@code value} to the BACK of the queue. */
    public void enqueue(Object value) {
        // TODO: implement this
        items.addLast(value);
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /**
     * Remove and return the value from the FRONT of the queue.
     *
     * @throws java.util.NoSuchElementException if the queue is empty
     */
    public Object dequeue() {
        // TODO: implement this
        if (items.isEmpty()) {
            throw new NoSuchElementException();
        }
        return items.removeFirst();
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /**
     * Return the FRONT value without removing it.
     *
     * @throws java.util.NoSuchElementException if the queue is empty
     */
    public Object peek() {
        // TODO: implement this
        if (items.isEmpty()) {
            throw new NoSuchElementException();
        }
        return items.peekFirst();
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /** Return {@code true} if the queue has no elements. */
    public boolean isEmpty() {
        // TODO: implement this
        return items.isEmpty();
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /** Return the number of elements in the queue. */
    public int size() {
        // TODO: implement this
        return items.size();
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    // -------------------------------------------------------------------------

    /**
     * TaskProcessor
     * =============
     * Simulates a simple task queue — like a message queue or HTTP request
     * pipeline.
     *
     * Producers call submitTask() to add work.
     * The processor calls processNext() or processAll() to handle the work
     * in the order it was received (FIFO).
     */
    public static class TaskProcessor {

        private final MyQueue queue;
        private final List<String> processed;

        public TaskProcessor() {
            this.queue = new MyQueue();
            this.processed = new ArrayList<>();
        }

        /**
         * Submit a task to be processed later.
         * Add it to the back of the queue.
         */
        public void submitTask(String task) {
            // TODO: implement this
            queue.enqueue(task);
            //throw new UnsupportedOperationException("Not implemented yet");
        }

        /**
         * Process the next pending task.
         *
         * - Dequeue the front task.
         * - Add it to the processed list.
         * - Return the task string.
         *
         * @throws java.util.NoSuchElementException if there are no pending tasks
         */
        public String processNext() {
            // TODO: implement this
            if (queue.isEmpty()) {
                throw new NoSuchElementException();
            }

            String task = (String) queue.dequeue();
            processed.add(task);
            return task;
            //throw new UnsupportedOperationException("Not implemented yet");
        }

        /**
         * Process ALL remaining tasks in order.
         *
         * Return a list of the tasks processed in this call, in order.
         */
        public List<String> processAll() {
            // TODO: implement this
            List<String> result = new ArrayList<>();

            while (!queue.isEmpty()) {
                String task = (String) queue.dequeue();
                processed.add(task);
                result.add(task);
            }

            return result;
            //throw new UnsupportedOperationException("Not implemented yet");
        }

        /** Return the number of tasks still waiting to be processed. */
        public int pendingCount() {
            // TODO: implement this
            return queue.size();
            //throw new UnsupportedOperationException("Not implemented yet");
        }

        /** Return all tasks that have been processed so far, in order. */
        public List<String> getProcessed() {
            return processed;
        }
    }
}
