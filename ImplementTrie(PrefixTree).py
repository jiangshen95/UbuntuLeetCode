class TrieNode:
    def __init__(self):
        self.isEnd = False
        self.children = {}
        
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                cur.children[ch] = TrieNode()
            cur = cur.children[ch]
        cur.isEnd = True

    def find(self, word):
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                return None
            cur = cur.children[ch]
        return cur
    
    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        t = self.find(word)
        return t != None and t.isEnd;

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        return self.find(prefix) != None
        
if __name__ == '__main__':
    trie = Trie();
    trie.insert("hello");
    print(trie.search("hello"))
    print(trie.search("hell"))
    print(trie.search("hellw"))
    print(trie.startsWith("hello"))
    print(trie.startsWith("helso"))
