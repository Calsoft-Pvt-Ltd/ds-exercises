"""
Exercise: Binary Search Tree (BST)
====================================
A BST is a binary tree where every node satisfies:
  - All values in the LEFT subtree are LESS than the node's value.
  - All values in the RIGHT subtree are GREATER than the node's value.

This property makes search, insert, and remove O(log n) on average (when
the tree is balanced) and O(n) worst case (e.g., inserting sorted values
degenerates the tree into a linked list).

Duplicate values are IGNORED — inserting an existing value is a no-op.

Your task: implement BSTNode first, then insert, search, remove, and inorder.
"""


class BSTNode:
    """
    A single node in the binary search tree.

    You need to implement __init__. A BSTNode needs:
      - value: an int stored at this node
      - left: the left child BSTNode (or None if no left child)
      - right: the right child BSTNode (or None if no right child)

    Hint: the constructor should accept a value argument.
    """
    # TODO: implement __init__
    def __init__(self, value: int):
        self.value = value
        self.left = None
        self.right = None
    pass


class BST:
    def __init__(self):
        """Initialize an empty BST with no nodes."""
        # TODO: implement this
        self.root = None
        pass

    def insert(self, value: int) -> None:
        """
        Insert value into the BST, maintaining the BST property.
        If value already exists, do nothing (no duplicates).
        """
        # TODO: implement this
        if self.root is None:
            self.root = BSTNode(value)
        else:
            self._insert_recursive(self.root, value)
        pass

    def _insert_recursive(self, node, value):
        if value < node.value:
            if node.left is None:
                node.left = BSTNode(value)
            else:
                self._insert_recursive(node.left, value)
        elif value > node.value:
            if node.right is None:
                node.right = BSTNode(value)
            else:
                self._insert_recursive(node.right, value)

    def search(self, value: int) -> bool:
        """
        Return True if value exists in the BST, False otherwise.

        Think about: at each node, how does the BST property let you
        discard half the remaining tree rather than scanning every node?
        """
        # TODO: implement this
        return self._search_recursive(self.root, value)
        pass

    def _search_recursive(self, node, value):
        if node is None:
            return False
        if value == node.value:
            return True
        elif value < node.value:
            return self._search_recursive(node.left, value)
        else:
            return self._search_recursive(node.right, value)

    def remove(self, value: int) -> bool:
        """
        Remove value from the BST. Return True if removed, False if not found.

        Three cases to handle:
          1. The node has NO children (leaf): simply unlink it.
          2. The node has ONE child: replace the node with its child.
          3. The node has TWO children: find the in-order successor (the
             smallest value in the right subtree), copy its value here,
             then remove the in-order successor from the right subtree.

        Think about: why does the in-order successor preserve the BST property?
        """
        # TODO: implement this
        self.root, removed = self._remove_recursive(self.root, value)
        return removed
        pass

    def _remove_recursive(self, node, value):
        if node is None:
            return None, False

        if value < node.value:
            node.left, removed = self._remove_recursive(node.left, value)
        elif value > node.value:
            node.right, removed = self._remove_recursive(node.right, value)
        else:
            removed = True
            # Case 1: Leaf
            if node.left is None and node.right is None:
                return None, removed
            # Case 2: One child
            elif node.left is None:
                return node.right, removed
            elif node.right is None:
                return node.left, removed
            # Case 3: Two children - find in-order successor
            else:
                successor = node.right
                while successor.left is not None:
                    successor = successor.left
                node.value = successor.value
                node.right, _ = self._remove_recursive(node.right, successor.value)

        return node, removed

    def inorder(self) -> list:
        """
        Return a list of all values in ascending (sorted) order.
        In-order traversal visits: left subtree → current node → right subtree.
        """
        # TODO: implement this
        result = []
        self._inorder_recursive(self.root, result)
        return result
        pass

    def _inorder_recursive(self, node, result):
        if node is None:
            return
        self._inorder_recursive(node.left, result)
        result.append(node.value)
        self._inorder_recursive(node.right, result)