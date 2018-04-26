class TrieNode:
    def __init__(self):
        self.word = ''
        self.children = {}

class Trie:
    def __init__(self):
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
        cur.word = word
    

class Solution:
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        def initTrie():
            for word in words:
                trie.insert(word)
        def searchWord(x, y, node):
            if board[x][y] == 'X':
                return
            if len(node.word) > 0:
                result.append(node.word)
                node.word = ''
            temp = board[x][y]
            board[x][y] = 'X'
            to = [[-1, 0], [0, 1], [1, 0], [0, -1]]
            for i in range(4):
                if 0 <= x + to[i][0] < m and 0 <= y + to[i][1] < n:
                    if board[x + to[i][0]][y + to[i][1]] in node.children:
                        searchWord(x + to[i][0], y + to[i][1], node.children[board[x + to[i][0]][y + to[i][1]]])
            board[x][y] = temp
        trie = Trie()
        initTrie()
        m = len(board)
        n = len(board[0])
        result = []
        for i in range(m):
            for j in range(n):
                if board[i][j] in trie.root.children:
                    searchWord(i, j, trie.root.children[board[i][j]])
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
        
