class Solution:
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if len(board)==0:
            return;
        m, n = len(board), len(board[0])
        save = [xy for k in range(max(m, n)) for xy in ((0, k), (m-1, k), (k, 0), (k, n-1))]
        while save:
            x, y = save.pop()
            if 0<=x<m and 0<=y<n and board[x][y]=='O':
                board[x][y] = 'U'
                save += (x, y-1), (x, y+1), (x-1, y), (x+1, y)
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
