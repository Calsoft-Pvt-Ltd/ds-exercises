package exercises;

import java.util.HashMap;
import java.util.Map;

/**
 * Exercise: Trie (Prefix Tree)
 * ================================
 * A trie stores strings by sharing common prefixes. Each node represents
 * one character. Walking from root to a node spells out a prefix. The
 * isEndOfWord flag marks where full words end.
 *
 * Example: inserting "app" and "apple" shares nodes for 'a', 'p', 'p'.
 * The second 'p' node has isEndOfWord = true (end of "app"), and the 'e'
 * node eventually has isEndOfWord = true (end of "apple").
 *
 * All operations are O(m) where m is the length of the word/prefix.
 *
 * Your task: implement TrieNode first, then the constructor and all methods
 * marked with TODO.
 */
public class Trie {

    /**
     * A single node in the trie.
     *
     * You need to implement this class. A TrieNode needs:
     *   - children: Map&lt;Character, TrieNode&gt; — maps each character to its
     *               child node. Initialize as a new HashMap.
     *   - isEndOfWord: boolean — true if an inserted word ends at this node.
     *                  Default: false
     *
     * Hint: write a no-arg constructor that initializes both fields.
     */
    public static class TrieNode {
        // TODO: declare fields (Map<Character, TrieNode> children, boolean isEndOfWord)
        // TODO: implement constructor
    }

    private TrieNode root;

    /**
     * Initialize the trie with an empty root TrieNode.
     * Start here — this is the first method to implement.
     */
    public Trie() {
        // TODO: initialize root
        throw new UnsupportedOperationException("Not implemented yet");
    }

    /**
     * Insert word into the trie.
     *
     * Walk from root, creating TrieNodes as needed for each character.
     * After processing all characters, mark the final node's isEndOfWord = true.
     */
    public void insert(String word) {
        // TODO: implement this
        throw new UnsupportedOperationException("Not implemented yet");
    }

    /**
     * Return true if word was previously inserted, false otherwise.
     *
     * Walk from root following each character. If a character's child doesn't
     * exist, return false. At the end, return isEndOfWord of the final node.
     *
     * Think about: why is isEndOfWord necessary? What goes wrong if you just
     * check whether the last node exists?
     */
    public boolean search(String word) {
        // TODO: implement this
        throw new UnsupportedOperationException("Not implemented yet");
    }

    /**
     * Return true if any inserted word starts with prefix.
     *
     * Walk from root following each character of prefix. If a character's
     * child doesn't exist, return false. If you reach the end of the prefix,
     * return true — isEndOfWord doesn't matter here.
     */
    public boolean startsWith(String prefix) {
        // TODO: implement this
        throw new UnsupportedOperationException("Not implemented yet");
    }
}
