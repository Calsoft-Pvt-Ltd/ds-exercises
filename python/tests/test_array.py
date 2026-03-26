import pytest
import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from exercises.array_exercise import FixedArray


# --- Initialization ---

def test_initial_size_is_zero():
    a = FixedArray(5)
    assert a.size() == 0

def test_capacity_is_respected():
    a = FixedArray(3)
    a.insert(0, "a")
    a.insert(1, "b")
    a.insert(2, "c")
    with pytest.raises(OverflowError):
        a.insert(0, "d")


# --- Insert ---

def test_insert_at_beginning():
    a = FixedArray(5)
    a.insert(0, 10)
    assert a.get(0) == 10
    assert a.size() == 1

def test_insert_shifts_elements_right():
    a = FixedArray(5)
    a.insert(0, 1)
    a.insert(1, 2)
    a.insert(2, 3)
    a.insert(1, 99)  # insert in middle
    assert a.get(0) == 1
    assert a.get(1) == 99
    assert a.get(2) == 2
    assert a.get(3) == 3

def test_insert_out_of_bounds_raises():
    a = FixedArray(5)
    with pytest.raises(IndexError):
        a.insert(1, 10)  # nothing at index 0 yet
    with pytest.raises(IndexError):
        a.insert(-1, 10)


# --- Get ---

def test_get_returns_correct_value():
    a = FixedArray(5)
    a.insert(0, 42)
    assert a.get(0) == 42

def test_get_out_of_bounds_raises():
    a = FixedArray(5)
    a.insert(0, 1)
    with pytest.raises(IndexError):
        a.get(1)
    with pytest.raises(IndexError):
        a.get(-1)


# --- Delete ---

def test_delete_reduces_size():
    a = FixedArray(5)
    a.insert(0, 1)
    a.insert(1, 2)
    a.insert(2, 3)
    a.delete(1)
    assert a.size() == 2

def test_delete_shifts_elements_left():
    a = FixedArray(5)
    a.insert(0, 1)
    a.insert(1, 2)
    a.insert(2, 3)
    a.delete(0)
    assert a.get(0) == 2
    assert a.get(1) == 3

def test_delete_out_of_bounds_raises():
    a = FixedArray(5)
    a.insert(0, 1)
    with pytest.raises(IndexError):
        a.delete(1)
    with pytest.raises(IndexError):
        a.delete(-1)


# --- Find ---

def test_find_existing_value():
    a = FixedArray(5)
    a.insert(0, 10)
    a.insert(1, 20)
    a.insert(2, 30)
    assert a.find(20) == 1

def test_find_first_occurrence():
    a = FixedArray(5)
    a.insert(0, 5)
    a.insert(1, 5)
    assert a.find(5) == 0

def test_find_missing_value():
    a = FixedArray(5)
    a.insert(0, 1)
    assert a.find(99) == -1


# --- Rotate Right ---

def test_rotate_right_basic():
    a = FixedArray(5)
    for i, v in enumerate([1, 2, 3, 4, 5]):
        a.insert(i, v)
    a.rotate_right(2)
    assert a.get(0) == 4
    assert a.get(1) == 5
    assert a.get(2) == 1
    assert a.get(3) == 2
    assert a.get(4) == 3

def test_rotate_right_by_size_is_noop():
    a = FixedArray(5)
    for i, v in enumerate([1, 2, 3]):
        a.insert(i, v)
    a.rotate_right(3)
    assert a.get(0) == 1
    assert a.get(1) == 2
    assert a.get(2) == 3

def test_rotate_right_k_larger_than_size():
    a = FixedArray(5)
    for i, v in enumerate([1, 2, 3]):
        a.insert(i, v)
    a.rotate_right(4)  # equivalent to rotate by 1
    assert a.get(0) == 3
    assert a.get(1) == 1
    assert a.get(2) == 2
