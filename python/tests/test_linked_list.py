import pytest
import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from exercises.linked_list_exercise import LinkedList


# --- Initialization ---

def test_empty_list_size():
    ll = LinkedList()
    assert ll.size() == 0

def test_empty_to_list():
    ll = LinkedList()
    assert ll.to_list() == []


# --- Append ---

def test_append_single():
    ll = LinkedList()
    ll.append(1)
    assert ll.to_list() == [1]
    assert ll.size() == 1

def test_append_multiple():
    ll = LinkedList()
    ll.append(1)
    ll.append(2)
    ll.append(3)
    assert ll.to_list() == [1, 2, 3]

def test_append_preserves_order():
    ll = LinkedList()
    for v in [10, 20, 30, 40]:
        ll.append(v)
    assert ll.to_list() == [10, 20, 30, 40]


# --- Prepend ---

def test_prepend_single():
    ll = LinkedList()
    ll.prepend(1)
    assert ll.to_list() == [1]

def test_prepend_multiple():
    ll = LinkedList()
    ll.prepend(3)
    ll.prepend(2)
    ll.prepend(1)
    assert ll.to_list() == [1, 2, 3]

def test_prepend_to_nonempty():
    ll = LinkedList()
    ll.append(2)
    ll.append(3)
    ll.prepend(1)
    assert ll.to_list() == [1, 2, 3]


# --- Delete ---

def test_delete_head():
    ll = LinkedList()
    ll.append(1)
    ll.append(2)
    ll.append(3)
    result = ll.delete(1)
    assert result is True
    assert ll.to_list() == [2, 3]

def test_delete_tail():
    ll = LinkedList()
    ll.append(1)
    ll.append(2)
    ll.append(3)
    ll.delete(3)
    assert ll.to_list() == [1, 2]

def test_delete_middle():
    ll = LinkedList()
    ll.append(1)
    ll.append(2)
    ll.append(3)
    ll.delete(2)
    assert ll.to_list() == [1, 3]

def test_delete_nonexistent_returns_false():
    ll = LinkedList()
    ll.append(1)
    result = ll.delete(99)
    assert result is False

def test_delete_from_empty():
    ll = LinkedList()
    result = ll.delete(1)
    assert result is False

def test_delete_only_first_occurrence():
    ll = LinkedList()
    ll.append(1)
    ll.append(2)
    ll.append(2)
    ll.append(3)
    ll.delete(2)
    assert ll.to_list() == [1, 2, 3]


# --- Find ---

def test_find_existing():
    ll = LinkedList()
    ll.append(1)
    ll.append(2)
    ll.append(3)
    assert ll.find(2) is True

def test_find_missing():
    ll = LinkedList()
    ll.append(1)
    assert ll.find(99) is False

def test_find_empty():
    ll = LinkedList()
    assert ll.find(1) is False


# --- Reverse ---

def test_reverse_multiple():
    ll = LinkedList()
    for v in [1, 2, 3, 4, 5]:
        ll.append(v)
    ll.reverse()
    assert ll.to_list() == [5, 4, 3, 2, 1]

def test_reverse_single():
    ll = LinkedList()
    ll.append(42)
    ll.reverse()
    assert ll.to_list() == [42]

def test_reverse_empty():
    ll = LinkedList()
    ll.reverse()
    assert ll.to_list() == []

def test_reverse_twice_restores_original():
    ll = LinkedList()
    for v in [1, 2, 3]:
        ll.append(v)
    ll.reverse()
    ll.reverse()
    assert ll.to_list() == [1, 2, 3]
