class Solution:
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def dfsfind(board, x, y):
            m, n = len(board), len(board[0])
            board[x][y] = 'U'
            if x>0 and board[x-1][y]=='O':
                dfsfind(board, x-1, y)
            if x<m-1 and board[x+1][y]=='O':
                dfsfind(board, x+1, y)
            if y>0 and board[x][y-1]=='O':
                dfsfind(board, x, y-1)
            if y<n-1 and board[x][y+1]=='O':
                dfsfind(board, x, y+1)
        if len(board)==0:
            return;
        m = len(board)
        n = len(board[0])
        for i in range(n):
            if board[0][i]=='O':
                dfsfind(board, 0, i)
            if board[m-1][i]=='O':
                dfsfind(board, m-1, i)
        for i in range(1, m-1):
            if board[i][0]=='O':
                dfsfind(board, i, 0)
            if board[i][n-1]=='O':
                dfsfind(board, i, n-1)
        for i in range(m):
            for j in range(n):
                if board[i][j]=='O':
                    board[i][j] = 'X'
                elif board[i][j]=='U':
                    board[i][j] = 'O'
                    
if __name__=='__main__':
    m = int(raw_input())
    board = []
    for i in range(m):
        board.append(list(raw_input()))
    solution = Solution()
    solution.solve(board)
    print(board)
