"""
Exercise: Trie (Prefix Tree)
=============================
A trie stores strings by sharing common prefixes. Each node represents
one character. Walking from the root to a node spells out a prefix.
The is_end_of_word flag marks where full words end.

Example: inserting "app" and "apple" shares nodes for 'a', 'p', 'p'.
The second 'p' node has is_end_of_word = True (end of "app"), and the
'e' node eventually has is_end_of_word = True (end of "apple").

All operations are O(m) where m is the length of the word/prefix.

Your task: implement TrieNode first, then insert, search, and starts_with.
"""


class TrieNode:
    """
    A single node in the trie.

    You need to implement __init__. A TrieNode needs:
      - children: a dict mapping each character (str of length 1) to the
                  child TrieNode for that character. Initialize as empty dict.
      - is_end_of_word: bool — True if an inserted word ends at this node.
                        Default: False
    """
    # TODO: implement __init__
    def __init__(self):
        # maps char -> TrieNode
        self.children = {}
        # marks end of a complete word
        self.is_end_of_word = False
    


class Trie:
    def __init__(self):
        """
        Initialize the trie with an empty root TrieNode.
        The root does not represent any character.
        """
        # TODO: implement this
        # root is an empty node
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        """
        Insert word into the trie.

        Walk from the root, creating TrieNodes as needed for each character.
        After processing all characters, mark the final node's
        is_end_of_word = True.
        """
        # TODO: implement this
        node = self.root

        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]

        # mark the end of the word
        node.is_end_of_word = True

    def search(self, word: str) -> bool:
        """
        Return True if word was previously inserted, False otherwise.

        Walk from root following each character. If a character's child
        doesn't exist, return False. At the end, return is_end_of_word.

        Think about: why is is_end_of_word necessary? What goes wrong if
        you just check whether the last node exists?
        """
        # TODO: implement this
        node = self.root

        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]

        return node.is_end_of_word

    def starts_with(self, prefix: str) -> bool:
        """
        Return True if any inserted word starts with prefix.

        Walk from root following each character of prefix. If a character's
        child doesn't exist, return False. If you reach the end of the prefix
        without getting stuck, return True — is_end_of_word doesn't matter here.
        """
        # TODO: implement this
        node = self.root

        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]

        return True
