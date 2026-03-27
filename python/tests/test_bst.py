import pytest  # useful for pytest.raises if you add error-handling tests
import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from exercises.bst_exercise import BST


# --- Insert / Inorder ---

def test_inorder_sorted():
    bst = BST()
    for v in [5, 3, 7, 1, 4]:
        bst.insert(v)
    assert bst.inorder() == [1, 3, 4, 5, 7]

def test_inorder_empty():
    bst = BST()
    assert bst.inorder() == []

def test_inorder_single():
    bst = BST()
    bst.insert(42)
    assert bst.inorder() == [42]

def test_insert_duplicate_ignored():
    bst = BST()
    bst.insert(5)
    bst.insert(5)
    assert bst.inorder() == [5]


# --- Search ---

def test_search_hit():
    bst = BST()
    bst.insert(5)
    assert bst.search(5) is True

def test_search_miss():
    bst = BST()
    bst.insert(5)
    assert bst.search(99) is False

def test_search_empty():
    bst = BST()
    assert bst.search(1) is False


# --- Remove ---

def test_remove_leaf():
    bst = BST()
    for v in [5, 3, 7]:
        bst.insert(v)
    assert bst.remove(3) is True
    assert bst.search(3) is False
    assert bst.inorder() == [5, 7]

def test_remove_one_child():
    bst = BST()
    for v in [5, 3, 7, 6]:
        bst.insert(v)
    assert bst.remove(7) is True
    assert bst.inorder() == [3, 5, 6]

def test_remove_two_children():
    bst = BST()
    for v in [5, 3, 7, 6, 8]:
        bst.insert(v)
    assert bst.remove(7) is True
    assert bst.inorder() == [3, 5, 6, 8]

def test_remove_root():
    bst = BST()
    for v in [5, 3, 7]:
        bst.insert(v)
    assert bst.remove(5) is True
    assert bst.search(5) is False
    assert bst.inorder() == [3, 7]

def test_remove_not_found():
    bst = BST()
    bst.insert(5)
    assert bst.remove(99) is False
    assert bst.inorder() == [5]

def test_inorder_sorted_after_remove():
    bst = BST()
    for v in [5, 3, 7, 1, 4, 6, 8]:
        bst.insert(v)
    bst.remove(3)
    result = bst.inorder()
    assert isinstance(result, list)
    assert result == sorted(result)

def test_search_false_after_remove():
    bst = BST()
    bst.insert(5)
    bst.remove(5)
    assert bst.search(5) is False

def test_remove_reinsert():
    bst = BST()
    for v in [5, 3, 7]:
        bst.insert(v)
    bst.remove(3)
    bst.insert(3)
    assert bst.search(3) is True
    assert bst.inorder() == [3, 5, 7]
