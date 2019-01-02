class Solution:
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        count = 0
        for i in range(len(board)):
            for j in range(len(board[i])):
                # if board[i][j] == 'X' and (i == 0 or board[i - 1][j] != 'X') and (j == 0 or board[i][j - 1] != 'X'):
                if board[i][j] == 'X' and not ((i > 0 and board[i - 1][j] == 'X') or (j > 0 and board[i][j - 1] == 'X')):
                    count += 1
        return count


if __name__ == '__main__':
    m = int(input())
    board = []
    for _ in range(m):
        board.append(list(input()))
    solution = Solution()
    print(solution.countBattleships(board))
