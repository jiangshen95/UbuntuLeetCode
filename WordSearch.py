class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def dfs(curr, word, board, i, j):
            if curr==len(word):
                return True
            if i<0 or j<0 or i>=len(board) or j>=len(board[0]) or board[i][j]!=word[curr]:
                return False
            temp=board[i][j]
            board[i][j]='#'
            if dfs(curr+1, word, board, i+1, j) or dfs(curr+1, word, board, i, j+1) \
            or dfs(curr+1, word, board, i-1, j) or dfs(curr+1, word, board, i, j-1):
                return True
            board[i][j]=temp
        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(0, word, board, i, j):
                    return True
        return False
        
if __name__=='__main__':
    board = []
    m = int(input())
    for i in range(m):
        s = raw_input()
        board+=[list(s)]
    word = raw_input()
    #print(board)
    solution = Solution()
    print(solution.exist(board, word))
            
