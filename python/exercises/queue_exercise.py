"""
Exercise 4: Queue (FIFO) + Task Processor
==========================================
A queue is a First-In, First-Out (FIFO) structure. The first element enqueued
is the first element dequeued. Think of a line at a coffee shop.

Real-world examples:
  - Message queues (RabbitMQ, SQS): tasks enqueued by producers, processed by consumers.
  - HTTP request pipelines: requests are handled in the order they arrive.
  - OS process scheduling: processes wait in a queue for CPU time.

Your task: implement all methods marked with TODO.
"""
from collections import deque


class Queue:
    def __init__(self):
        """
        Initialize an empty queue.

        Use Python's collections.deque as your internal storage.
        Deque supports O(1) append (enqueue) and O(1) popleft (dequeue).
        A plain list would give O(n) for dequeue — think about why.
        """
        self._data = deque()

    def enqueue(self, value) -> None:
        """Add `value` to the BACK of the queue."""
        self._data.append(value)

    def dequeue(self):
        """
        Remove and return the value from the FRONT of the queue.
        Raise IndexError with the message "dequeue from empty queue" if empty.
        """
        if self.is_empty():
            raise IndexError("dequeue from empty queue")
        return self._data.popleft()

    def peek(self):
        """
        Return the FRONT value without removing it.
        Raise IndexError with the message "peek at empty queue" if empty.
        """
        if self.is_empty():
            raise IndexError("peek at empty queue")
        return self._data[0]

    def is_empty(self) -> bool:
        """Return True if the queue has no elements."""
        return len(self._data) == 0

    def size(self) -> int:
        """Return the number of elements in the queue."""
        return len(self._data)


class TaskProcessor:
    """
    Simulates a simple task queue — like a message queue or HTTP request pipeline.

    Producers call submit_task() to add work.
    The processor calls process_next() or process_all() to handle the work
    in the order it was received (FIFO).
    """

    def __init__(self):
        self.queue = Queue()
        self.processed: list = []

    def submit_task(self, task: str) -> None:
        """
        Submit a task to be processed later.
        Add it to the back of the queue.
        """
        self.queue.enqueue(task)

    def process_next(self) -> str:
        """
        Process the next pending task.

        - Dequeue the front task.
        - Append it to self.processed.
        - Return the task string.

        Raise IndexError with the message "no pending tasks" if the queue is empty.
        """
        if self.queue.is_empty():
            raise IndexError("no pending tasks")

        task = self.queue.dequeue()
        self.processed.append(task)
        return task
    

    def process_all(self) -> list:
        """
        Process ALL remaining tasks in order.

        Return a list of all tasks that were processed in this call,
        in the order they were processed.
        """
        results = []
        while not self.queue.is_empty():
            task = self.process_next()
            results.append(task)
        return results

    def pending_count(self) -> int:
        """Return the number of tasks still waiting to be processed."""
        return self.queue.size()
