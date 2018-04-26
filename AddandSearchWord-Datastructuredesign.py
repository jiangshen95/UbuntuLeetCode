class TrieNode:
    def __init__(self):
        self.isEnd = False
        self.children = {}
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                cur.children[ch] = TrieNode()
            cur = cur.children[ch]
        cur.isEnd = True

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        def search(i, cur):
            if i == len(word):
                return cur.isEnd;
            if word[i] == '.':
                for ch in cur.children:
                    if search(i+1, cur.children[ch]):
                        return True
                return False
            else:
                if word[i] not in cur.children:
                    return False
                return search(i+1, cur.children[word[i]])
        return search(0, self.root)
        
if __name__ == '__main__':
    dic = WordDictionary();
    dic.addWord("bad");
    dic.addWord("dad");
    dic.addWord("mad");
    print(dic.search("pad"))
    print(dic.search("bad"))
    print(dic.search(".ad"))
    print(dic.search("b.."))
