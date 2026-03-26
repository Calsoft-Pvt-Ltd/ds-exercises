#pragma once
#include <string>
#include <unordered_map>

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
 * Your task: implement TrieNode in trie.cpp, then all methods marked TODO.
 */
class Trie {
public:
    Trie();
    ~Trie();  // pre-implemented — recursively deletes all nodes for you

    /** Insert word into the trie. */
    void insert(const std::string& word);

    /**
     * Return true if word was previously inserted, false otherwise.
     * Think about: why is isEndOfWord necessary?
     */
    bool search(const std::string& word) const;

    /**
     * Return true if any inserted word starts with prefix.
     * Unlike search(), you do NOT check isEndOfWord here.
     */
    bool startsWith(const std::string& prefix) const;

    // Non-copyable — owns heap-allocated nodes
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

private:
    struct TrieNode;  // implemented in trie.cpp — see the TODO there
    TrieNode* root_;
    static void destroyNode(TrieNode* node);
};
