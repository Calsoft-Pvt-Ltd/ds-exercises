import pytest
import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from exercises.stack_exercise import Stack, is_balanced


# --- Initialization ---

def test_new_stack_is_empty():
    s = Stack()
    assert s.is_empty() is True
    assert s.size() == 0


# --- Push / Pop ---

def test_push_increases_size():
    s = Stack()
    s.push(1)
    assert s.size() == 1
    s.push(2)
    assert s.size() == 2

def test_pop_returns_last_pushed():
    s = Stack()
    s.push(1)
    s.push(2)
    s.push(3)
    assert s.pop() == 3
    assert s.pop() == 2
    assert s.pop() == 1

def test_pop_decreases_size():
    s = Stack()
    s.push(10)
    s.push(20)
    s.pop()
    assert s.size() == 1

def test_pop_empty_raises():
    s = Stack()
    with pytest.raises(IndexError):
        s.pop()

def test_lifo_order():
    s = Stack()
    items = [1, 2, 3, 4, 5]
    for item in items:
        s.push(item)
    result = [s.pop() for _ in range(len(items))]
    assert result == [5, 4, 3, 2, 1]


# --- Peek ---

def test_peek_returns_top():
    s = Stack()
    s.push(7)
    s.push(8)
    assert s.peek() == 8

def test_peek_does_not_remove():
    s = Stack()
    s.push(42)
    s.peek()
    assert s.size() == 1
    assert s.peek() == 42

def test_peek_empty_raises():
    s = Stack()
    with pytest.raises(IndexError):
        s.peek()


# --- is_balanced ---

def test_balanced_simple_parens():
    assert is_balanced("()") is True

def test_balanced_nested():
    assert is_balanced("({[]})") is True

def test_balanced_with_other_chars():
    assert is_balanced("hello(world[!])") is True

def test_balanced_empty_string():
    assert is_balanced("") is True

def test_unbalanced_wrong_order():
    assert is_balanced("({[})") is False

def test_unbalanced_unclosed():
    assert is_balanced("(((") is False

def test_unbalanced_extra_close():
    assert is_balanced("))") is False

def test_unbalanced_close_before_open():
    assert is_balanced(")()") is False

def test_balanced_multiple_pairs():
    assert is_balanced("()[]{}") is True

def test_unbalanced_mismatched():
    assert is_balanced("(]") is False
