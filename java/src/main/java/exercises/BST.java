package exercises;

import java.util.ArrayList;
import java.util.List;
/** * Exercise: Binary Search Tree (BST)
 *  * ===================================== 
 * A BST is a binary tree where every node satisfies:
 * - All values in the LEFT subtree are LESS than the node's value. 
 * - All values in the RIGHT subtree are GREATER than the node's value. 
 * This property makes search, insert, and remove O(log n) on average 
 * (balanced tree) and O(n) worst case (e.g., inserting sorted values). *
 * Duplicate values are IGNORED — inserting an existing value is a no-op. * 
 * Your task: implement BSTNode first, then the constructor and all methods *
 * marked with TODO. */
public class BST {
/** * A single node in the binary search tree. 
  * You need to implement this class. A BSTNode needs: 
  * - value: int — the value stored at this node 
  * - left: BSTNode — the left child (or null if none)
  * - right: BSTNode — the right child (or null if none) 
  * Hint: write a constructor that accepts a value argument and 
  * initializes left and right to null. */
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
    /** * Initialize an empty BST. 
     * Start here — this is the first method to implement. */

    public BST() {
        root = null;
    }
    /** Insert value into the BST, maintaining the BST property. 
     * If value already exists, do nothing (no duplicates). */

    public void insert(int value) {
        root = insertRec(root, value);
    }

    private BSTNode insertRec(BSTNode node, int value) {
        if (node == null) return new BSTNode(value);

        if (value < node.value) {
            node.left = insertRec(node.left, value);
        } else if (value > node.value) {
            node.right = insertRec(node.right, value);
        }
        // duplicate → do nothing
        return node; // ignore duplicate
    }

    /** Return true if value exists in the BST, false otherwise. 
     * Think about: at each node, how does the BST property let you 
     * discard half the remaining tree rather than scanning every node? */
    public boolean search(int value) {
        BSTNode current = root;

        while (current != null) {
            if (value == current.value) return true;
            else if (value < current.value) current = current.left;
            else current = current.right;
        }

        return false;
    }

    public boolean remove(int value) {
        Result result = new Result();
        root = removeRec(root, value, result);
        return result.deleted;
    }

    // helper class to track deletion
    private static class Result {
        boolean deleted = false;
    }

    private BSTNode removeRec(BSTNode node, int value, Result result) {
        if (node == null) return null;

        if (value < node.value) {
            node.left = removeRec(node.left, value, result);
        } else if (value > node.value) {
            node.right = removeRec(node.right, value, result);
        } else {
            result.deleted = true;

            // case 1: no child
            if (node.left == null && node.right == null) {
                return null;
            }

            // case 2: one child
            if (node.left == null) return node.right;
            if (node.right == null) return node.left;

            // case 3: two children
            BSTNode successor = findMin(node.right);
            node.value = successor.value;
            node.right = removeRec(node.right, successor.value, new Result());
        }

        return node;
    }

    private BSTNode findMin(BSTNode node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }
    /**Return all values in ascending (sorted) order. 
     * In-order traversal: left subtree → current node → right subtree. */
    public List<Integer> inorder() {
        List<Integer> result = new ArrayList<>();
        inorderRec(root, result);
        return result;
    }

    private void inorderRec(BSTNode node, List<Integer> result) {
        if (node == null) return;

        inorderRec(node.left, result);
        result.add(node.value);
        inorderRec(node.right, result);
    }
}