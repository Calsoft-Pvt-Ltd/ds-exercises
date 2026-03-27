package exercises;

import java.util.ArrayList;
import java.util.List;

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
 * Your task: implement BSTNode first, then the constructor and all methods
 * marked with TODO.
 */
public class BST {

    /**
     * A single node in the binary search tree.
     *
     * You need to implement this class. A BSTNode needs:
     *   - value: int — the value stored at this node
     *   - left: BSTNode — the left child (or null if none)
     *   - right: BSTNode — the right child (or null if none)
     *
     * Hint: write a constructor that accepts a value argument and
     * initializes left and right to null.
     */
    public static class BSTNode {
        // TODO: declare fields (int value, BSTNode left, BSTNode right)
        // TODO: implement constructor
         int value;
        BSTNode left;
        BSTNode right;

        public BSTNode(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }

    }

    private BSTNode root;

    /**
     * Initialize an empty BST.
     * Start here — this is the first method to implement.
     */
    public BST() {
        // TODO: initialize root to null
        root = null;
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    /**
     * Insert value into the BST, maintaining the BST property.
     * If value already exists, do nothing (no duplicates).
     */
    public void insert(int value) {
        // TODO: implement this
        //throw new UnsupportedOperationException("Not implemented yet");
        root = insertHelper(root, value);
    }

    private BSTNode insertHelper(BSTNode node, int value) {
        if (node == null) {
            return new BSTNode(value);
        }

        if (value < node.value) {
            node.left = insertHelper(node.left, value);
        } else if (value > node.value) {
            node.right = insertHelper(node.right, value);
        }

        return node;
    }

    /**
     * Return true if value exists in the BST, false otherwise.
     *
     * Think about: at each node, how does the BST property let you
     * discard half the remaining tree rather than scanning every node?
     */
    public boolean search(int value) {
        // TODO: implement this
        return search(root, value);
       // throw new UnsupportedOperationException("Not implemented yet");
    }
     private boolean search(BSTNode node, int value) {
        if (node == null) return false;

        if (value == node.value) return true;
        if (value < node.value) return search(node.left, value);
        else return search(node.right, value);
    }

    /**
     * Remove value from the BST. Return true if removed, false if not found.
     *
     * Three cases to handle:
     *   1. Node has NO children (leaf): simply unlink it.
     *   2. Node has ONE child: replace the node with its child.
     *   3. Node has TWO children: find the in-order successor (the smallest
     *      value in the right subtree), copy its value to this node, then
     *      remove the in-order successor from the right subtree.
     *
     * Think about: why does the in-order successor preserve the BST property?
     */
    public boolean remove(int value) {
        // TODO: implement this
         if (!search(value)) return false;
        root = remove(root, value);
        return true;
        //throw new UnsupportedOperationException("Not implemented yet");
    }
     private BSTNode remove(BSTNode node, int value) {
        if (node == null) return null;

        if (value < node.value) {
            node.left = remove(node.left, value);
        } else if (value > node.value) {
            node.right = remove(node.right, value);
        } else {
            // Case 1: no child
            if (node.left == null && node.right == null) {
                return null;
            }

            // Case 2: one child
            if (node.left == null) {
                return node.right;
            }
            if (node.right == null) {
                return node.left;
            }

            // Case 3: two children
            int successorValue = findMin(node.right);
            node.value = successorValue;
            node.right = remove(node.right, successorValue);
        }

        return node;
    }
    private int findMin(BSTNode node) {
        while (node.left != null) {
            node = node.left;
        }
        return node.value;
    }


    /**
     * Return all values in ascending (sorted) order.
     * In-order traversal: left subtree → current node → right subtree.
     */
    public List<Integer> inorder() {
        // TODO: implement this
         List<Integer> result = new ArrayList<>();
        inorder(root, result);
        return result;
        //throw new UnsupportedOperationException("Not implemented yet");
    }
    private void inorder(BSTNode node, List<Integer> result) {
        if (node == null) return;

        inorder(node.left, result);
        result.add(node.value);
        inorder(node.right, result);
    }
}
