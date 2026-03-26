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
    def __init__(self, value: int):
        self.value = value
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        """Initialize an empty BST with no nodes."""
        self.root = None

    def insert(self, value: int) -> None:
        """
        Insert value into the BST, maintaining the BST property.
        If value already exists, do nothing (no duplicates).
        """
        if self.root is None:
            self.root = BSTNode(value)
            return

        node = self.root
        while True:
            if value < node.value:
                if node.left is None:
                    node.left = BSTNode(value)
                    return
                node = node.left
            elif value > node.value:
                if node.right is None:
                    node.right = BSTNode(value)
                    return
                node = node.right
            else:
                return

    def search(self, value: int) -> bool:
        """
        Return True if value exists in the BST, False otherwise.

        Think about: at each node, how does the BST property let you
        discard half the remaining tree rather than scanning every node?
        """
        node = self.root
        while node is not None:
            if value < node.value:
                node = node.left
            elif value > node.value:
                node = node.right
            else:
                return True
        return False

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
        def _remove(node, value):
            if node is None:
                return None, False
            if value < node.value:
                node.left, removed = _remove(node.left, value)
                return node, removed
            if value > node.value:
                node.right, removed = _remove(node.right, value)
                return node, removed
            # value == node.value
            if node.left is None:
                return node.right, True
            if node.right is None:
                return node.left, True
            successor = node.right
            while successor.left is not None:
                successor = successor.left
            node.value = successor.value
            node.right, _ = _remove(node.right, successor.value)
            return node, True

        self.root, removed = _remove(self.root, value)
        return removed

    def inorder(self) -> list:
        """
        Return a list of all values in ascending (sorted) order.
        In-order traversal visits: left subtree → current node → right subtree.
        """
        result = []

        def _traverse(node):
            if node is None:
                return
            _traverse(node.left)
            result.append(node.value)
            _traverse(node.right)

        _traverse(self.root)
        return result
