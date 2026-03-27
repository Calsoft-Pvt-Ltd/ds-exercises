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

        public BSTNode(int value){
            this.value = value;
        }

    }

    private BSTNode root;

    /**
     * Initialize an empty BST.
     * Start here — this is the first method to implement.
     */
    public BST() {
      this.root = null;
    }

    /**
     * Insert value into the BST, maintaining the BST property.
     * If value already exists, do nothing (no duplicates).
     */
    public void insert(int value) {
         root = insertRecursive(root, value);
    }

    private BSTNode insertRecursive(BSTNode node, int value){
        if(node == null) return new  BSTNode(value);

        if(node.value > value) node.left = insertRecursive(node.left, value);

        else if (node.value < value) node.right = insertRecursive(node.right, value);

        return node;
    }

    /**
     * Return true if value exists in the BST, false otherwise.
     *
     * Think about: at each node, how does the BST property let you
     * discard half the remaining tree rather than scanning every node?
     */
    public boolean search(int value) {
        BSTNode node = root;

        while (node != null) {
            if(value == node.value) return true;
            else if (value < node.value) node = node.left;
            else node = node.right;
        }
        return false;
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
        if (!search(value)) {
        return false;
    }

    root = removeRecu(root, value);
    return true;
    }

    private BSTNode removeRecu(BSTNode node, int val){
        if(node == null) return null;

        if(node.value > val) node.left = removeRecu(node.left, val);
        else if (node.value < val) node.right = removeRecu( node.right, val);
        else{
            if(node.left == null && node.right == null)return null;
            else if (node.left == null || node.right == null){
                if (node.left == null) return node.right;
                else return node.left;
            }
             
            int smallestValue = findMin(node.right);
            node.value = smallestValue;
            node.right = removeRecu(node.right, smallestValue);
        }

        return node;
    }
 
    private int findMin(BSTNode node){
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
       List<Integer> ans  = new ArrayList<>();
       inorderRecu(root, ans);
       return ans;
    }

    private void inorderRecu(BSTNode node, List<Integer> ans){
        if(node == null) return;

        inorderRecu(node.left, ans);
        ans.add(node.value);
        inorderRecu(node.right, ans);
    }
}
