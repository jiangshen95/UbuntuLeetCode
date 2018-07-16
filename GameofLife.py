class Solution:
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])

        for i in range(m):
            for j in range(n):
                count = 0
                for I in range(max(0, i - 1), min(m, i + 2)):
                    for J in range(max(0, j - 1), min(n, j + 2)):
                        count += board[I][J] & 1
                if count == 3 or count - board[i][j] == 3:
                    board[i][j] |= 2
        for i in range(m):
            for j in range(n):
                board[i][j] >>= 1


if __name__ == '__main__':
    m = int(input())
    board = []
    for i in range(m):
        board.append([int(num) for num in input().split()])
    solution = Solution()
    solution.gameOfLife(board)
    print(board)

