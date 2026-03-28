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
     root_ = new TrieNode();// placeholder — replace with the line above
    //
    // Note: body assignment (not an initializer list) is used here because
    // TrieNode is an incomplete type at the point of Trie's declaration.
    // It's only fully defined below in this .cpp file.
}
 
 
// ─── insert ───────────────────────────────────────────────────────────────
 
void Trie::insert(const std::string& word) {
    // TODO: implement this
    // Walk from root_, creating TrieNodes as needed for each character.
    // After all characters, set the final node's isEndOfWord = true.
    TrieNode* current = root_;
 
    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }
 
    current->isEndOfWord = true;
}
 
 
// ─── search ───────────────────────────────────────────────────────────────
 
bool Trie::search(const std::string& word) const {
    // TODO: implement this
    // Walk from root_ following each character. If a child doesn't exist,
    // return false. At the end, return the node's isEndOfWord.
    if(!root_) {
        return false;
    }    

    TrieNode* current = root_;
 
    for (char ch : word) {
        if (current->children.find(ch) == current->children.end()) {
            return false;
        }
        current = current->children.at(ch);
    }
 
    return current->isEndOfWord;// placeholder
}
 
 
// ─── startsWith ───────────────────────────────────────────────────────────
 
bool Trie::startsWith(const std::string& prefix) const {
    // TODO: implement this
    // Walk from root_ following each character of prefix. If a child doesn't
    // exist, return false. If you reach the end of prefix, return true.
    if(!root_) {
        return false;
    }    


     TrieNode* current = root_;
 
    for (char ch : prefix) {
        if (current->children.find(ch) == current->children.end()) {
            return false;
        }
        current = current->children.at(ch);
    }
 
    return true;
}
 