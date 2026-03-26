#include "trie.h"

// ─── TrieNode ──────────────────────────────────────────────────────────────
//
// TODO: implement TrieNode.
//
// A TrieNode needs:
//   - children: std::unordered_map<char, TrieNode*>
//               Maps each character to its child node. Initialize as empty map.
//   - isEndOfWord: bool
//               True if an inserted word ends at this node. Default: false.
//
// Write a constructor that initializes isEndOfWord = false.
// (children will default-initialize to an empty map automatically.)
//
struct Trie::TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    // TODO: implement constructor

    TrieNode() : isEndOfWord(false) {}
};


// ─── Destructor (pre-implemented) ─────────────────────────────────────────

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
    // TODO: implement this
    // Initialize root_ to a freshly allocated TrieNode.
    // root_ = new TrieNode();
    //-- root_ = nullptr; // placeholder — replace with the line above
    //
    // Note: body assignment (not an initializer list) is used here because
    // TrieNode is an incomplete type at the point of Trie's declaration.
    // It's only fully defined below in this .cpp file.

    root_ = new TrieNode();
}


// ─── insert ───────────────────────────────────────────────────────────────

void Trie::insert(const std::string& word) {
    // TODO: implement this
    // Walk from root_, creating TrieNodes as needed for each character.
    // After all characters, set the final node's isEndOfWord = true.

    TrieNode* current = root_;

    for (char c : word) {
        // agar child exist nahi karta → create karo
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }

        // next node pe move karo
        current = current->children[c];
    }

    // last node mark karo
    current->isEndOfWord = true;
}


// ─── search ───────────────────────────────────────────────────────────────

bool Trie::search(const std::string& word) const {
    // TODO: implement this
    // Walk from root_ following each character. If a child doesn't exist,
    // return false. At the end, return the node's isEndOfWord.
    // return false; // placeholder

    TrieNode* current = root_;

    for (char c : word) {
        if (current->children.find(c) == current->children.end()) {
            return false;
        }

        current = current->children.at(c);
    }

    return current->isEndOfWord;
}


// ─── startsWith ───────────────────────────────────────────────────────────

bool Trie::startsWith(const std::string& prefix) const {
    // TODO: implement this
    // Walk from root_ following each character of prefix. If a child doesn't
    // exist, return false. If you reach the end of prefix, return true.
    // return false; // placeholder

    TrieNode* current = root_;

    for (char c : prefix) {
        if (current->children.find(c) == current->children.end()) {
            return false;
        }

        current = current->children.at(c);
    }

    return true;
}
