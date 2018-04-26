class TrieNode:
    def __init__(self):
        self.isEnd = False
        self.children = {}

class Trie:
    def __init__(self):
        self.root = TrieNode()
        self.endNode = None
        
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
    
    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                return False
            cur = cur.children[ch]
        self.endNode = cur
        return cur.isEnd

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        cur = self.root
        for ch in prefix:
            if ch not in cur.children:
                return False
            cur = cur.children[ch]
        return True
    

class Solution:
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        def searchWord(x, y, word):
            if board[x][y] == 'X':
                return
            word += board[x][y]
            if not trie.startsWith(word):
                return
            if trie.search(word):
                result.append(word)
                trie.endNode.isEnd = False
            temp = board[x][y]
            board[x][y] = 'X'
            to = [[-1, 0], [0, 1], [1, 0], [0, -1]]
            for i in range(4):
                if 0 <= x + to[i][0] < m and 0 <= y + to[i][1] < n:
                    searchWord(x + to[i][0], y + to[i][1], word)
            board[x][y] = temp
        trie = Trie()
        for word in words:
            trie.insert(word)
        m = len(board)
        n = len(board[0])
        result = []
        for i in range(m):
            for j in range(n):
                searchWord(i, j, "")
        return result

if __name__ == '__main__':
    m = int(raw_input())
    board = []
    for i in range(m):
        raw = raw_input()
        board.append(list(raw))
    n = int(raw_input())
    words = []
    for i in range(n):
        word = raw_input()
        words.append(word)
    solution = Solution()
    print(solution.findWords(board, words))
        
