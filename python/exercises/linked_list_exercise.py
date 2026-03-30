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

        pass

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
            curr = self.head
            while curr.next:
                curr = curr.next
            curr.next = new_node
        
        self._size+=1
        

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
        self._size+=1
        

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
        if not self.head:
            return False
        
        # case 1 when you have to delete head
        if self.head.value == value:
            self.head = self.head.next
            self._size-=1
            return True
        
        # case 2 delete somewhere in the middle
        prev = self.head
        curr =  self.head.next

        while curr:
            if curr.value == value:
                prev.next = curr.next
                self._size -=1
                return True
            
            prev = curr
            curr = curr.next

        return False

    def find(self, value) -> bool:
        """Return True if `value` exists in the list, False otherwise."""
        # TODO: implement this

        curr = self.head
        while curr:
            if curr.value == value:
                return True
            curr = curr.next
            
        return False
        pass

    def reverse(self) -> None:
        """
        Reverse the list IN-PLACE by re-wiring the .next pointers.

        Do NOT create a new list or use extra data structures.
        After reversing, the old tail becomes the new head.

        Hint: you need to track three pointers simultaneously — prev, current, next.
        """
        # TODO: implement this
        prev = None
        curr = self.head

        while curr:
            next_node = curr.next  # save next before overwriting
            curr.next = prev       # reverse the pointer
            prev = curr            # move prev forward
            curr = next_node       # move curr forward

        self.head = prev
        pass

    def to_list(self) -> list:
        """
        Return all values as a Python list in order from head to tail.
        Useful for testing and printing.
        """
        # TODO: implement this
        result = []
        curr = self.head
        while curr:
            result.append(curr.value)
            curr = curr.next
        return result
        pass

    def size(self) -> int:
        """Return the number of nodes in the list."""
        # TODO: implement this
        return self._size
        pass

    def __repr__(self) -> str:
        return " -> ".join(str(v) for v in self.to_list()) + " -> None"