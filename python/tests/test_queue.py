import pytest
import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from exercises.queue_exercise import Queue, TaskProcessor


# --- Initialization ---

def test_new_queue_is_empty():
    q = Queue()
    assert q.is_empty() is True
    assert q.size() == 0


# --- Enqueue / Dequeue ---

def test_enqueue_increases_size():
    q = Queue()
    q.enqueue(1)
    assert q.size() == 1

def test_dequeue_returns_first_enqueued():
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)
    assert q.dequeue() == 1

def test_fifo_order():
    q = Queue()
    items = [10, 20, 30, 40]
    for item in items:
        q.enqueue(item)
    result = []
    while not q.is_empty():
        result.append(q.dequeue())
    assert result == [10, 20, 30, 40]

def test_dequeue_decreases_size():
    q = Queue()
    q.enqueue("a")
    q.enqueue("b")
    q.dequeue()
    assert q.size() == 1

def test_dequeue_empty_raises():
    q = Queue()
    with pytest.raises(IndexError):
        q.dequeue()


# --- Peek ---

def test_peek_returns_front():
    q = Queue()
    q.enqueue("first")
    q.enqueue("second")
    assert q.peek() == "first"

def test_peek_does_not_remove():
    q = Queue()
    q.enqueue(99)
    q.peek()
    assert q.size() == 1

def test_peek_empty_raises():
    q = Queue()
    with pytest.raises(IndexError):
        q.peek()


# --- TaskProcessor ---

def test_submit_increases_pending():
    tp = TaskProcessor()
    tp.submit_task("task-1")
    tp.submit_task("task-2")
    assert tp.pending_count() == 2

def test_process_next_returns_task():
    tp = TaskProcessor()
    tp.submit_task("email-job")
    result = tp.process_next()
    assert result == "email-job"

def test_process_next_fifo_order():
    tp = TaskProcessor()
    tp.submit_task("first")
    tp.submit_task("second")
    tp.submit_task("third")
    assert tp.process_next() == "first"
    assert tp.process_next() == "second"

def test_process_next_decreases_pending():
    tp = TaskProcessor()
    tp.submit_task("a")
    tp.submit_task("b")
    tp.process_next()
    assert tp.pending_count() == 1

def test_process_next_empty_raises():
    tp = TaskProcessor()
    with pytest.raises(IndexError):
        tp.process_next()

def test_process_all_returns_all_tasks():
    tp = TaskProcessor()
    tp.submit_task("a")
    tp.submit_task("b")
    tp.submit_task("c")
    result = tp.process_all()
    assert result == ["a", "b", "c"]

def test_process_all_clears_queue():
    tp = TaskProcessor()
    tp.submit_task("x")
    tp.submit_task("y")
    tp.process_all()
    assert tp.pending_count() == 0

def test_processed_history_accumulates():
    tp = TaskProcessor()
    tp.submit_task("job-1")
    tp.submit_task("job-2")
    tp.process_next()
    tp.submit_task("job-3")
    tp.process_all()
    assert tp.processed == ["job-1", "job-2", "job-3"]
