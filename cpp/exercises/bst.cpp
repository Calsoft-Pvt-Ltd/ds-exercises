#include "bst.h"
#include<functional>

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
    BSTNode(int val) : value(val), left(nullptr), right(nullptr) {}
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
      if (root_ == nullptr) {
        root_ = new BSTNode(value);
        return;
    }

    BSTNode* current = root_;

    while (true) {
        if (value == current->value) {
            return; // already exists
        }
        else if (value < current->value) {
            if (current->left == nullptr) {
                current->left = new BSTNode(value);
                return;
            }
            current = current->left;
        }
        else { // value > current->value
            if (current->right == nullptr) {
                current->right = new BSTNode(value);
                return;
            }
            current = current->right;
        }
    }
}


// ─── search ───────────────────────────────────────────────────────────────

bool BST::search(int value) const {
    // TODO: implement this
    // Traverse the tree: go left if value < current, right if value > current.
    // Return true if found, false if you reach nullptr.
      BSTNode* current = root_;

    while (current != nullptr) {
        if (value == current->value) {
            return true;
        } 
        else if (value < current->value) {
            current = current->left;
        } 
        else {
            current = current->right;
        }
    }

    return false;
}


// ─── remove ───────────────────────────────────────────────────────────────

bool BST::remove(int value) {
    // TODO: implement this
    // Return false if value not found.
    // Case 1 (leaf): unlink and delete.
    // Case 2 (one child): replace node with its child.
    // Case 3 (two children): find in-order successor (leftmost in right subtree),
    //   copy its value, then remove the in-order successor.
      BSTNode* parent = nullptr;
    BSTNode* current = root_;

    // find node
    while (current != nullptr && current->value != value) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == nullptr) {
        return false; // not found
    }

    // Case 3: two children
    if (current->left != nullptr && current->right != nullptr) {
        BSTNode* succParent = current;
        BSTNode* successor = current->right;

        while (successor->left != nullptr) {
            succParent = successor;
            successor = successor->left;
        }

        current->value = successor->value;

        // delete successor instead
        current = successor;
        parent = succParent;
    }

    // Case 1 & 2: 0 or 1 child
    BSTNode* child;
    if (current->left != nullptr) {
        child = current->left;
    } else {
        child = current->right;
    }

    if (parent == nullptr) {
        root_ = child;
    }
    else if (parent->left == current) {
        parent->left = child;
    }
    else {
        parent->right = child;
    }

    delete current;
    return true;
}


// ─── inorder ──────────────────────────────────────────────────────────────

std::vector<int> BST::inorder() const {
    std::vector<int> result;

    std::function<void(BSTNode*)> dfs = [&](BSTNode* node) {
        if (!node) return;
        dfs(node->left);
        result.push_back(node->value);
        dfs(node->right);
    };

    dfs(root_);
    return result;
}