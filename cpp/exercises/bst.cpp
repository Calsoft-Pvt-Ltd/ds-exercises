#include "bst.h"
#include <vector>

// ─── BSTNode ───────────────────────────────────────────────────────────────
struct BST::BSTNode {
    int value;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// ─── Destructor ────────────────────────────────────────────────────────────
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
    BSTNode** curr = &root_;
    while (*curr) {
        if (value < (*curr)->value) {
            curr = &((*curr)->left);
        } else if (value > (*curr)->value) {
            curr = &((*curr)->right);
        } else {
            // Value already exists, do nothing
            return;
        }
    }
    *curr = new BSTNode(value);
}

// ─── search ───────────────────────────────────────────────────────────────
bool BST::search(int value) const {
    BSTNode* curr = root_;
    while (curr) {
        if (value < curr->value) {
            curr = curr->left;
        } else if (value > curr->value) {
            curr = curr->right;
        } else {
            return true;
        }
    }
    return false;
}

// ─── remove ───────────────────────────────────────────────────────────────
bool BST::remove(int value) {
    BSTNode** curr = &root_;

    while (*curr && (*curr)->value != value) {
        if (value < (*curr)->value) {
            curr = &((*curr)->left);
        } else {
            curr = &((*curr)->right);
        }
    }

    if (!*curr) return false; // Not found

    BSTNode* node = *curr;

    // Case 1: leaf node
    if (!node->left && !node->right) {
        delete node;
        *curr = nullptr;
    }
    // Case 2: one child
    else if (!node->left || !node->right) {
        *curr = node->left ? node->left : node->right;
        delete node;
    }
    // Case 3: two children
    else {
        // In-order successor: leftmost node in right subtree
        BSTNode** succ = &(node->right);
        while ((*succ)->left) {
            succ = &((*succ)->left);
        }
        node->value = (*succ)->value; // Copy successor value
        BSTNode* tmp = *succ;
        *succ = (*succ)->right;       // Remove successor
        delete tmp;
    }

    return true;
}

// ─── inorder ──────────────────────────────────────────────────────────────
// File-local helper (not a member)
static void inorderHelper(BST::BSTNode* node, std::vector<int>& result) {
    if (!node) return;
    inorderHelper(node->left, result);
    result.push_back(node->value);
    inorderHelper(node->right, result);
}

std::vector<int> BST::inorder() const {
    std::vector<int> result;
    inorderHelper(root_, result);
    return result;
}