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
        self._items = []

    def push(self, value) -> None:
        """Add `value` to the top of the stack."""
        self._items.append(value)

    def pop(self):
        """
        Remove and return the top value.
        Raise IndexError with the message "pop from empty stack" if empty.
        """
        if not self._items:
            raise IndexError("pop from empty stack")
        return self._items.pop()

    def peek(self):
        """
        Return the top value WITHOUT removing it.
        Raise IndexError with the message "peek at empty stack" if empty.
        """
        if not self._items:
            raise IndexError("peek at empty stack")
        return self._items[-1]

    def is_empty(self) -> bool:
        """Return True if the stack has no elements."""
        return len(self._items) == 0

    def size(self) -> int:
        """Return the number of elements in the stack."""
        return len(self._items)


def is_balanced(s: str) -> bool:
    """
    Use your Stack to determine whether the bracket/paren/brace characters
    in `s` are balanced.

    Rules:
      - Every opening bracket must have a matching closing bracket.
      - Brackets must close in the correct order.
      - Valid pairs: () [] {}

    Examples:
      is_balanced("()")          → True
      is_balanced("({[]})")      → True
      is_balanced("hello(world)")→ True   (non-bracket chars are ignored)
      is_balanced("({[})")       → False  (wrong closing order)
      is_balanced("(((")         → False  (unclosed brackets)
      is_balanced("))")          → False  (closes before any open)

    Algorithm hint:
      - Push every opening bracket onto the stack.
      - When you see a closing bracket, check that it matches the top of the stack.
      - At the end, the stack should be empty.
    """
    stack = Stack()
    pairs = {')': '(', ']': '[', '}': '{'}
    for ch in s:
        if ch in '([{':
            stack.push(ch)
        elif ch in ')]}':
            if stack.is_empty() or stack.pop() != pairs[ch]:
                return False
    return stack.is_empty()
