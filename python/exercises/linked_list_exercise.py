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
        # TODO: implement this
        self.head = None
        self._size = 0

    def append(self, value) -> None:
        """
        Add a new node with `value` at the END of the list.

        If the list is empty, the new node becomes the head.
        Otherwise, walk to the last node and set its .next pointer.

        Think about: why is this O(n) unless you maintain a tail pointer?
        """
        # TODO: implement this
        new_node = Node(value)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
        self._size += 1

    def prepend(self, value) -> None:
        """
        Add a new node with `value` at the BEGINNING of the list.

        This is O(1) — one of the key advantages of linked lists over arrays.
        Think about: why can't an array do this in O(1)?
        """
        # TODO: implement this
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node
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
        # TODO: implement this
        current = self.head
        prev = None

        while current:
            if current.value == value:
                if prev: # middle or tail
                    prev.next = current.next
                else: #head
                    self.head = current.next
                self._size -= 1
                return True
            prev = current
            current = current.next

        return False #not found

    def find(self, value) -> bool:
        """Return True if `value` exists in the list, False otherwise."""
        # TODO: implement this
        current = self.head

        while current:
            if current.value == value:
                return True
            current = current.next
        
        return False
            

    def reverse(self) -> None:
        """
        Reverse the list IN-PLACE by re-wiring the .next pointers.

        Do NOT create a new list or use extra data structures.
        After reversing, the old tail becomes the new head.

        Hint: you need to track three pointers simultaneously — prev, current, next.
        """
        # TODO: implement this
        current = self.head
        prev = None
        next = None
        while current:
            next = current.next
            current.next = prev
            prev = current
            current = next

        self.head = prev

    def to_list(self) -> list:
        """
        Return all values as a Python list in order from head to tail.
        Useful for testing and printing.
        """
        # TODO: implement this
        current = self.head
        elements = []
        while current:
            elements.append(current.value)
            current = current.next
        
        return elements

    def size(self) -> int:
        """Return the number of nodes in the list."""
        # TODO: implement this
        return self._size

    def __repr__(self) -> str:
        return " -> ".join(str(v) for v in self.to_list()) + " -> None"
