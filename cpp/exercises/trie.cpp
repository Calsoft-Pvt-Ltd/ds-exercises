#include "trie.h"
#include <unordered_map>

// ─── TrieNode ──────────────────────────────────────────────────────────────

struct Trie::TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    // Constructor
    TrieNode() : isEndOfWord(false) {}
};


// ─── Destructor ───────────────────────────────────────────────────────────

void Trie::destroyNode(TrieNode* node) {
    if (!node) return;
    for (auto& [ch, child] : node->children) {
        destroyNode(child);
    }
    delete node;
}

Trie::~Trie() {
    destroyNode(root_);
}


// ─── Constructor ──────────────────────────────────────────────────────────

Trie::Trie() {
    root_ = new TrieNode();  // FIXED
}


// ─── insert ───────────────────────────────────────────────────────────────

void Trie::insert(const std::string& word) {
    TrieNode* curr = root_;

    for (char c : word) {
        // If character not present → create node
        if (curr->children.find(c) == curr->children.end()) {
            curr->children[c] = new TrieNode();
        }

        curr = curr->children[c];
    }

    curr->isEndOfWord = true;
}


// ─── search ───────────────────────────────────────────────────────────────

bool Trie::search(const std::string& word) const {
    TrieNode* curr = root_;

    for (char c : word) {
        if (curr->children.find(c) == curr->children.end()) {
            return false;
        }
        curr = curr->children.at(c);
    }

    return curr->isEndOfWord;
}


// ─── startsWith ───────────────────────────────────────────────────────────

bool Trie::startsWith(const std::string& prefix) const {
    TrieNode* curr = root_;

    for (char c : prefix) {
        if (curr->children.find(c) == curr->children.end()) {
            return false;
        }
        curr = curr->children.at(c);
    }

    return true;
}