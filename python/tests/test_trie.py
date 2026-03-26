import pytest  # useful for pytest.raises if you add error-handling tests
import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from exercises.trie_exercise import Trie


# --- Insert / Search ---

def test_insert_then_search():
    t = Trie()
    t.insert("hello")
    assert t.search("hello") is True

def test_search_missing_word():
    t = Trie()
    t.insert("hello")
    assert t.search("world") is False

def test_search_empty_trie():
    t = Trie()
    assert t.search("hello") is False


# --- starts_with ---

def test_starts_with_valid_prefix():
    t = Trie()
    t.insert("apple")
    assert t.starts_with("app") is True

def test_starts_with_invalid_prefix():
    t = Trie()
    t.insert("apple")
    assert t.starts_with("xyz") is False

def test_starts_with_full_word():
    t = Trie()
    t.insert("apple")
    assert t.starts_with("apple") is True


# --- Shared prefix ---

def test_shared_prefix_search_longer():
    t = Trie()
    t.insert("apple")
    t.insert("app")
    assert t.search("apple") is True

def test_shared_prefix_search_shorter():
    t = Trie()
    t.insert("apple")
    t.insert("app")
    assert t.search("app") is True

def test_shared_prefix_search_partial_only():
    t = Trie()
    t.insert("apple")
    t.insert("app")
    assert t.search("ap") is False


# --- Duplicate insert ---

def test_insert_duplicate_no_crash():
    t = Trie()
    t.insert("hello")
    t.insert("hello")
    assert t.search("hello") is True


# --- Empty string ---

def test_insert_empty_string_then_search():
    t = Trie()
    t.insert("")
    assert t.search("") is True

def test_starts_with_empty_prefix_nonempty_trie():
    t = Trie()
    t.insert("hello")
    assert t.starts_with("") is True

def test_search_empty_string_on_empty_trie():
    t = Trie()
    assert t.search("") is False
