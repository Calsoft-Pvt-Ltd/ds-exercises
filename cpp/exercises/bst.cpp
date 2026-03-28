#include "bst.h"
#include <functional>  // for std::function in inorder()

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
    if (!root_) {
        root_ = new BSTNode(value);
        return;
    }

    BSTNode* current = root_;

    while (true) {
        if (value < current->value) {
            if (!current->left) {
                current->left = new BSTNode(value);
                return;
            }
            current = current->left;
        }
        else if (value > current->value) {
            if (!current->right) {
                current->right = new BSTNode(value);
                return;
            }
            current = current->right;
        }
        else {
            // Duplicate value — ignore
            return;
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
        if (value == current->value)
            return true;

        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    return false;
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
    BSTNode* parent = nullptr;
    BSTNode* current = root_;
     while (current && current->value != value) {
        parent = current;

        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    if (!current)
        return false;

    if (current->left && current->right) {
        BSTNode* successorParent = current;
        BSTNode* successor = current->right;

        while (successor->left) {
            successorParent = successor;
            successor = successor->left;
        }

        current->value = successor->value;

        parent = successorParent;
        current = successor;
    }

    BSTNode* child;

    if (current->left)
        child = current->left;
    else
        child = current->right;

    if (!parent)
        root_ = child;
    else if (parent->left == current)
        parent->left = child;
    else
        parent->right = child;

    delete current;

    return true;
    return false; // placeholder
}


// ─── inorder ──────────────────────────────────────────────────────────────

// static void inorderTraversal(BST::BSTNode* node,
//                              std::vector<int>& result) {
//     if (!node)
//         return;

//     inorderTraversal(node->left, result);
//     result.push_back(node->value);
//     inorderTraversal(node->right, result);
// }

std::vector<int> BST::inorder() const {
    // TODO: implement this
    // In-order traversal: left → current → right.
    // Collect values into a vector and return it.
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
