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

    public static class TrieNode {
        // TODO: declare fields (Map<Character, TrieNode> children, boolean isEndOfWord)
        Map<Character, TrieNode> children;
        boolean isEndOfWord;

        // TODO: implement constructor
        public TrieNode() {
            children = new HashMap<>();
            isEndOfWord = false;
        }
    }

    private TrieNode root;

    /**
     * Initialize the trie with an empty root TrieNode.
     * Start here — this is the first method to implement.
     */
    public Trie() {
        // TODO: initialize root
        root = new TrieNode();
    }

    /**
     * Insert word into the trie.
     *
     * Walk from root, creating TrieNodes as needed for each character.
     * After processing all characters, mark the final node's isEndOfWord = true.
     */
    public void insert(String word) {
        // TODO: implement this
        TrieNode current = root;

        for (char c : word.toCharArray()) {
            current.children.putIfAbsent(c, new TrieNode());
            current = current.children.get(c);
        }

        current.isEndOfWord = true;
    }

    /**
     * Return true if word was previously inserted, false otherwise.
     *
     * Walk from root following each character. If a character's child doesn't
     * exist, return false. At the end, return isEndOfWord of the final node.
     */
    public boolean search(String word) {
        // TODO: implement this
        TrieNode current = root;

        for (char c : word.toCharArray()) {
            if (!current.children.containsKey(c)) {
                return false;
            }
            current = current.children.get(c);
        }

        return current.isEndOfWord;
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
        TrieNode current = root;

        for (char c : prefix.toCharArray()) {
            if (!current.children.containsKey(c)) {
                return false;
            }
            current = current.children.get(c);
        }

        return true;
    }
}
