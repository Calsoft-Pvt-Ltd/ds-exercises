package exercises;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;

public class BSTTest {

    // --- Insert / Inorder ---

    @Test
    void inorderReturnsSortedValues() {
        BST bst = new BST();
        for (int v : new int[]{5, 3, 7, 1, 4}) bst.insert(v);
        assertEquals(List.of(1, 3, 4, 5, 7), bst.inorder());
    }

    @Test
    void inorderEmpty() {
        BST bst = new BST();
        assertTrue(bst.inorder().isEmpty());
    }

    @Test
    void inorderSingleElement() {
        BST bst = new BST();
        bst.insert(42);
        assertEquals(List.of(42), bst.inorder());
    }

    @Test
    void insertDuplicateIgnored() {
        BST bst = new BST();
        bst.insert(5);
        bst.insert(5);
        assertEquals(List.of(5), bst.inorder());
    }

    // --- Search ---

    @Test
    void searchHit() {
        BST bst = new BST();
        bst.insert(5);
        assertTrue(bst.search(5));
    }

    @Test
    void searchMiss() {
        BST bst = new BST();
        bst.insert(5);
        assertFalse(bst.search(99));
    }

    @Test
    void searchEmptyTree() {
        BST bst = new BST();
        assertFalse(bst.search(1));
    }

    // --- Remove ---

    @Test
    void removeLeaf() {
        BST bst = new BST();
        for (int v : new int[]{5, 3, 7}) bst.insert(v);
        assertTrue(bst.remove(3));
        assertFalse(bst.search(3));
        assertEquals(List.of(5, 7), bst.inorder());
    }

    @Test
    void removeOneChild() {
        BST bst = new BST();
        for (int v : new int[]{5, 3, 7, 6}) bst.insert(v);
        assertTrue(bst.remove(7));
        assertEquals(List.of(3, 5, 6), bst.inorder());
    }

    @Test
    void removeTwoChildren() {
        BST bst = new BST();
        for (int v : new int[]{5, 3, 7, 6, 8}) bst.insert(v);
        assertTrue(bst.remove(7));
        assertEquals(List.of(3, 5, 6, 8), bst.inorder());
    }

    @Test
    void removeRoot() {
        BST bst = new BST();
        for (int v : new int[]{5, 3, 7}) bst.insert(v);
        assertTrue(bst.remove(5));
        assertFalse(bst.search(5));
        assertEquals(List.of(3, 7), bst.inorder());
    }

    @Test
    void removeNotFound() {
        BST bst = new BST();
        bst.insert(5);
        assertFalse(bst.remove(99));
        assertEquals(List.of(5), bst.inorder());
    }

    @Test
    void inorderSortedAfterRemove() {
        BST bst = new BST();
        for (int v : new int[]{5, 3, 7, 1, 4, 6, 8}) bst.insert(v);
        bst.remove(3);
        assertEquals(List.of(1, 4, 5, 6, 7, 8), bst.inorder());
    }

    @Test
    void searchFalseAfterRemove() {
        BST bst = new BST();
        bst.insert(5);
        bst.remove(5);
        assertFalse(bst.search(5));
    }

    @Test
    void removeReinsert() {
        BST bst = new BST();
        for (int v : new int[]{5, 3, 7}) bst.insert(v);
        bst.remove(3);
        bst.insert(3);
        assertTrue(bst.search(3));
        assertEquals(List.of(3, 5, 7), bst.inorder());
    }
}