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

    // Constructor
    BSTNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
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
            return; // duplicate, do nothing
        }
        else if (value < current->value) {
            if (current->left == nullptr) {
                current->left = new BSTNode(value);
                return;
            }
            current = current->left;
        }
        else {
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
    // return false; // placeholder

     BSTNode* current = root_;

    while (current != nullptr) {
        if (value == current->value) return true;

        if (value < current->value)
            current = current->left;
        else
            current = current->right;
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
    // return false; // placeholder

    BSTNode* parent = nullptr;
    BSTNode* current = root_;

    // Step 1: find the node
    while (current != nullptr && current->value != value) {
        parent = current;
        if (value < current->value)
            current = current->left;
        else
            current = current->right;
    }

    // not found
    if (current == nullptr) return false;

    // Case 3: two children
    if (current->left != nullptr && current->right != nullptr) {
        BSTNode* succParent = current;
        BSTNode* successor = current->right;

        // find leftmost node
        while (successor->left != nullptr) {
            succParent = successor;
            successor = successor->left;
        }

        // copy value
        current->value = successor->value;

        // now delete successor instead
        parent = succParent;
        current = successor;
    }

    // Case 1 & 2 (0 or 1 child)
    BSTNode* child = (current->left != nullptr) ? current->left : current->right;

    // if deleting root
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
    // TODO: implement this
    // In-order traversal: left → current → right.
    // Collect values into a vector and return it.
    // return {}; // placeholder

    std::vector<int> result;
    std::stack<BSTNode*> st;
    BSTNode* current = root_;

    while (current != nullptr || !st.empty()) {

        // left side jao
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        // process node
        current = st.top();
        st.pop();

        result.push_back(current->value);

        // right side jao
        current = current->right;
    }

    return result;
}
