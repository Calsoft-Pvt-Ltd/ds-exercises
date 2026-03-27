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


class BST:
    def __init__(self):
        """Initialize an empty BST with no nodes."""
        # TODO: implement this
        self.root = None

    def insert(self, value: int) -> None:
        """
        Insert value into the BST, maintaining the BST property.
        If value already exists, do nothing (no duplicates).
        """
        # TODO: implement this
        def _insert(node, val):
            if node is None:
                return BSTNode(val)
            if val < node.value:
                node.left = _insert(node.left, val)
            elif val > node.value:
                node.right = _insert(node.right, val)
            return node
        self.root = _insert(self.root, value)

    def search(self, value: int) -> bool:
        """
        Return True if value exists in the BST, False otherwise.

        Think about: at each node, how does the BST property let you
        discard half the remaining tree rather than scanning every node?
        """
        # TODO: implement this
        def _search(node, val):
            if node is None:
                return False
            if val == node.value:
                return True
            if val < node.value:
                return _search(node.left, val)
            return _search(node.right, val)
        return _search(self.root, value)

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
        def _remove(node, val):
            if node is None:
                return node, False
            if val < node.value:
                node.left, removed = _remove(node.left, val)
            elif val > node.value:
                node.right, removed = _remove(node.right, val)
            else:
                removed = True
                if node.left is None:
                    return node.right, removed
                if node.right is None:
                    return node.left, removed
                # two children: find in-order successor (min of right subtree)
                successor = node.right
                while successor.left:
                    successor = successor.left
                node.value = successor.value
                node.right, _ = _remove(node.right, successor.value)
            return node, removed
        self.root, removed = _remove(self.root, value)
        return removed

    def inorder(self) -> list:
        """
        Return a list of all values in ascending (sorted) order.
        In-order traversal visits: left subtree → current node → right subtree.
        """
        # TODO: implement this
        result = []
        def _inorder(node):
            if node is None:
                return
            _inorder(node.left)
            result.append(node.value)
            _inorder(node.right)
        _inorder(self.root)
        return result
