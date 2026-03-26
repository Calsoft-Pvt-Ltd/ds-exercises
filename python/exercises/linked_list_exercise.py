"""
Exercise 2: Singly Linked List
===============================
Unlike arrays, linked lists have NO fixed size. Each element (node) holds a
value and a pointer to the next node. There is no contiguous memory block —
nodes can live anywhere in memory.

Trade-off: insertion and deletion at the head are O(1), but random access is
O(n) because you must walk the chain of pointers.

Your task: implement all methods marked with TODO.
"""


class Node:
    def __init__(self, value):
        self.value = value
        self.next = None  # pointer to the next node


class LinkedList:
    def __init__(self):
        """
        Initialize an empty linked list.
        Keep track of the head node and the size.
        """
        self.head = None
        self._size = 0

    def append(self, value) -> None:
        """
        Add a new node with `value` at the END of the list.

        If the list is empty, the new node becomes the head.
        Otherwise, walk to the last node and set its .next pointer.

        Think about: why is this O(n) unless you maintain a tail pointer?
        """
        node = Node(value)
        if self.head is None:
            self.head = node
        else:
            cur = self.head
            while cur.next is not None:
                cur = cur.next
            cur.next = node
        self._size += 1

    def prepend(self, value) -> None:
        """
        Add a new node with `value` at the BEGINNING of the list.

        This is O(1) — one of the key advantages of linked lists over arrays.
        Think about: why can't an array do this in O(1)?
        """
        node = Node(value)
        node.next = self.head
        self.head = node
        self._size += 1

    def delete(self, value) -> bool:
        """
        Delete the FIRST node whose value equals `value`.

        Return True if a node was deleted, False if the value was not found.

        You need to handle three cases:
          1. The list is empty.
          2. The node to delete is the head.
          3. The node to delete is somewhere in the middle or tail.

        Think about: why do you need a reference to the PREVIOUS node?
        """
        if self.head is None:
            return False
        if self.head.value == value:
            self.head = self.head.next
            self._size -= 1
            return True
        prev = self.head
        cur = self.head.next
        while cur is not None:
            if cur.value == value:
                prev.next = cur.next
                self._size -= 1
                return True
            prev = cur
            cur = cur.next
        return False

    def find(self, value) -> bool:
        """Return True if `value` exists in the list, False otherwise."""
        cur = self.head
        while cur is not None:
            if cur.value == value:
                return True
            cur = cur.next
        return False

    def reverse(self) -> None:
        """
        Reverse the list IN-PLACE by re-wiring the .next pointers.

        Do NOT create a new list or use extra data structures.
        After reversing, the old tail becomes the new head.

        Hint: you need to track three pointers simultaneously — prev, current, next.
        """
        prev = None
        cur = self.head
        while cur is not None:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        self.head = prev

    def to_list(self) -> list:
        """
        Return all values as a Python list in order from head to tail.
        Useful for testing and printing.
        """
        result = []
        cur = self.head
        while cur is not None:
            result.append(cur.value)
            cur = cur.next
        return result

    def size(self) -> int:
        """Return the number of nodes in the list."""
        return self._size

    def __repr__(self) -> str:
        return " -> ".join(str(v) for v in self.to_list()) + " -> None"
