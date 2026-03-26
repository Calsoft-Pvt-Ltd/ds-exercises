package exercises;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class TrieTest {

    // --- Insert / Search ---

    @Test
    void insertThenSearch() {
        Trie t = new Trie();
        t.insert("hello");
        assertTrue(t.search("hello"));
    }

    @Test
    void searchMissingWord() {
        Trie t = new Trie();
        t.insert("hello");
        assertFalse(t.search("world"));
    }

    @Test
    void searchEmptyTrie() {
        Trie t = new Trie();
        assertFalse(t.search("hello"));
    }

    // --- startsWith ---

    @Test
    void startsWithValidPrefix() {
        Trie t = new Trie();
        t.insert("apple");
        assertTrue(t.startsWith("app"));
    }

    @Test
    void startsWithInvalidPrefix() {
        Trie t = new Trie();
        t.insert("apple");
        assertFalse(t.startsWith("xyz"));
    }

    @Test
    void startsWithFullWord() {
        Trie t = new Trie();
        t.insert("apple");
        assertTrue(t.startsWith("apple"));
    }

    // --- Shared prefix ---

    @Test
    void sharedPrefixSearchLonger() {
        Trie t = new Trie();
        t.insert("apple");
        t.insert("app");
        assertTrue(t.search("apple"));
    }

    @Test
    void sharedPrefixSearchShorter() {
        Trie t = new Trie();
        t.insert("apple");
        t.insert("app");
        assertTrue(t.search("app"));
    }

    @Test
    void sharedPrefixPartialOnly() {
        Trie t = new Trie();
        t.insert("apple");
        t.insert("app");
        assertFalse(t.search("ap"));
    }

    // --- Duplicate insert ---

    @Test
    void insertDuplicateNoChange() {
        Trie t = new Trie();
        t.insert("hello");
        t.insert("hello");
        assertTrue(t.search("hello"));
    }

    // --- Empty string ---

    @Test
    void insertEmptyStringThenSearch() {
        Trie t = new Trie();
        t.insert("");
        assertTrue(t.search(""));
    }

    @Test
    void startsWithEmptyPrefixNonEmptyTrie() {
        Trie t = new Trie();
        t.insert("hello");
        assertTrue(t.startsWith(""));
    }

    @Test
    void searchEmptyStringOnEmptyTrie() {
        Trie t = new Trie();
        assertFalse(t.search(""));
    }
}
