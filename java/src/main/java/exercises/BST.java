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
        root = insertRec(root, value);
        //throw new UnsupportedOperationException("Not implemented yet");
    }

    private BSTNode insertRec(BSTNode node, int value) {
        if (node == null) {
            return new BSTNode(value);
        }

        if (value < node.value) {
            node.left = insertRec(node.left, value);
        } else if (value > node.value) {
            node.right = insertRec(node.right, value);
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
        BSTNode current = root;
        while (current != null) {
            if (value == current.value) {
                return true;
            } else if (value < current.value) {
                current = current.left;
            } else {
                current = current.right;
            }
        }
        return false;
        //throw new UnsupportedOperationException("Not implemented yet");
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
        if (!search(value)) {
            return false;
        }
        root = removeRec(root, value);
        return true;
    }

    private BSTNode removeRec(BSTNode node, int value) {
        if (node == null) return null;

        if (value < node.value) {
            node.left = removeRec(node.left, value);
        } else if (value > node.value) {
            node.right = removeRec(node.right, value);
        } else {

            if (node.left == null && node.right == null) {
                return null;
            }

            if (node.left == null) {
                return node.right;
            }

            if (node.right == null) {
                return node.left;
            }

            int successor = findMin(node.right);
            node.value = successor;
            node.right = removeRec(node.right, successor);
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
        inorderRec(root, result);
        return result;
        //throw new UnsupportedOperationException("Not implemented yet");
    }
    private void inorderRec(BSTNode node, List<Integer> result) {
        if (node == null) return;

        inorderRec(node.left, result);
        result.add(node.value);
        inorderRec(node.right, result);
    }
}
