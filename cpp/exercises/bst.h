#pragma once
#include <vector>

/**
 * Exercise: Binary Search Tree (BST)
 * =====================================
 * A BST is a binary tree where every node satisfies:
 *   - All values in the LEFT subtree are LESS than the node's value.
 *   - All values in the RIGHT subtree are GREATER than the node's value.
 *
 * This property makes search, insert, and remove O(log n) on average
 * (balanced tree) and O(n) worst case (e.g., inserting sorted values).
 *
 * Duplicate values are IGNORED — inserting an existing value is a no-op.
 *
 * Your task: implement BSTNode in bst.cpp, then all methods marked TODO.
 */
class BST {
public:
    BST();
    ~BST();  // pre-implemented — recursively deletes all nodes for you

    /**
     * Insert value into the BST, maintaining the BST property.
     * Duplicates are ignored.
     */
    void insert(int value);

    /** Return true if value exists in the BST, false otherwise. */
    bool search(int value) const;

    /**
     * Remove value from the BST. Return true if removed, false if not found.
     *
     * Three cases:
     *   1. Leaf node: simply unlink it.
     *   2. One child: replace the node with its child.
     *   3. Two children: replace with in-order successor (min of right subtree),
     *      then remove the in-order successor from the right subtree.
     */
    bool remove(int value);

    /** Return all values in ascending order (in-order traversal). */
    std::vector<int> inorder() const;

    // Non-copyable — owns heap-allocated nodes
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;

private:
    struct BSTNode;  // implemented in bst.cpp — see the TODO there
    BSTNode* root_;
    static void destroyNode(BSTNode* node);
};
