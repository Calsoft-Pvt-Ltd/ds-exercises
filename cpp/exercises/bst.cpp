#include "bst.h"

// ─── BSTNode ───────────────────────────────────────────────────────────────
//
// TODO: implement BSTNode.
//
// A BSTNode needs:
//   - value: int — the value stored at this node
//   - left:  BSTNode* — left child (nullptr if none)
//   - right: BSTNode* — right child (nullptr if none)
//
// Write a constructor that accepts a value argument and sets left = right = nullptr.
//
struct BST::BSTNode {
    int value;
    BSTNode* left;
    BSTNode* right;
    // TODO: implement constructor
};


// ─── Destructor (pre-implemented) ─────────────────────────────────────────

void BST::destroyNode(BSTNode* node) {
    if (!node) return;
    destroyNode(node->left);
    destroyNode(node->right);
    delete node;
}

BST::~BST() {
    destroyNode(root_);
}


// ─── Constructor ──────────────────────────────────────────────────────────

BST::BST() : root_(nullptr) {}


// ─── insert ───────────────────────────────────────────────────────────────

void BST::insert(int value) {
    // TODO: implement this
    // Find the correct position using the BST property (left < current < right).
    // If value already exists, do nothing.
}


// ─── search ───────────────────────────────────────────────────────────────

bool BST::search(int value) const {
    // TODO: implement this
    // Traverse the tree: go left if value < current, right if value > current.
    // Return true if found, false if you reach nullptr.
    return false; // placeholder
}


// ─── remove ───────────────────────────────────────────────────────────────

bool BST::remove(int value) {
    // TODO: implement this
    // Return false if value not found.
    // Case 1 (leaf): unlink and delete.
    // Case 2 (one child): replace node with its child.
    // Case 3 (two children): find in-order successor (leftmost in right subtree),
    //   copy its value, then remove the in-order successor.
    return false; // placeholder
}


// ─── inorder ──────────────────────────────────────────────────────────────

std::vector<int> BST::inorder() const {
    // TODO: implement this
    // In-order traversal: left → current → right.
    // Collect values into a vector and return it.
    return {}; // placeholder
}
