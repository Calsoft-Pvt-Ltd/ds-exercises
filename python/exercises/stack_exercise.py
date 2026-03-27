"""
Exercise 3: Stack (LIFO)
=========================
A stack is a Last-In, First-Out (LIFO) structure. The last element pushed is
the first element popped. Think of a stack of plates — you add and remove from
the top only.

Real-world example: the CALL STACK. Every time a function is called, a frame
is pushed. When the function returns, its frame is popped. This is why infinite
recursion causes a "stack overflow".

Your task: implement all methods marked with TODO.
"""


class Stack:
    def __init__(self):
        """Initialize an empty stack."""
        self._data = []

    def push(self, value) -> None:
        """Add `value` to the top of the stack."""
        self._data.append(value)

    def pop(self):
        """
        Remove and return the top value.
        Raise IndexError with the message "pop from empty stack" if empty.
        """
        if self.is_empty():
            raise IndexError("pop from empty stack")
        return self._data.pop()

    def peek(self):
        """
        Return the top value WITHOUT removing it.
        Raise IndexError with the message "peek at empty stack" if empty.
        """
        if self.is_empty():
            raise IndexError("peek at empty stack")
        return self._data[-1]

    def is_empty(self) -> bool:
        """Return True if the stack has no elements."""
        return len(self._data) == 0

    def size(self) -> int:
        """Return the number of elements in the stack."""
        return len(self._data)


def is_balanced(s: str) -> bool:
    """
    Use your Stack to determine whether the bracket/paren/brace characters
    in `s` are balanced.
    """
    stack = Stack()
    pairs = {')': '(', ']': '[', '}': '{'}
    for char in s:
        if char in '([{':
            stack.push(char)
        elif char in ')]}':
            if stack.is_empty() or stack.pop() != pairs[char]:
                return False
    return stack.is_empty()