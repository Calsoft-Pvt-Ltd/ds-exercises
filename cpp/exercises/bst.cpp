#include "bst.h"
#include <stack>

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

     BSTNode* new_node = new BSTNode(value);
    if (!root_) {
        root_ = new_node;
        return;
    }
    BSTNode* current = root_;
    while (true) {
        if (value == current->value) {
            delete new_node;
            return;
        }
        if (value < current->value) {
            if (!current->left) { current->left = new_node; return; }
            current = current->left;
        } else {
            if (!current->right) { current->right = new_node; return; }
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
    while (current) {
        if (value == current->value) return true;
        current = (value < current->value) ? current->left : current->right;
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
 
   
    while (current && current->value != value) {
        parent = current;
        current = (value < current->value) ? current->left : current->right;
    }
    if (!current) return false; 
 

    if (current->left && current->right) {
        BSTNode* successor_parent = current;
        BSTNode* successor = current->right;
        while (successor->left) {
            successor_parent = successor;
            successor = successor->left;
        }
        current->value = successor->value;
    
        current = successor;
        parent = successor_parent;
    }
 
 
    BSTNode* child = current->left ? current->left : current->right;
    if (!parent) {
        root_ = child; 
    } else if (parent->left == current) {
        parent->left = child;
    } else {
        parent->right = child;
    }
    delete current;
    return true;
}


// ─── inorder ──────────────────────────────────────────────────────────────




// std::vector<int> BST::inorder() const {
//     // TODO: implement this
//     // In-order traversal: left → current → right.
//     // Collect values into a vector and return it.
//      std::vector<int> result;
//     inorderHelper(root_, result);
//     return result;
// }

std::vector<int> BST::inorder() const {
    std::vector<int> result;
    std::stack<BSTNode*> stack;
    BSTNode* current = root_;
    while (current || !stack.empty()) {
        while (current) {
            stack.push(current);
            current = current->left;
        }
        current = stack.top();
        stack.pop();
        result.push_back(current->value);
        current = current->right;
    }
    return result;
}