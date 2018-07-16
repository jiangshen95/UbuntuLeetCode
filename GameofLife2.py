import collections

class Solution:
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def gameOfLifeInfinite(live):
            ctr = collections.Counter((I, J) for i, j in live
                                      for I in range(i - 1, i + 2)
                                      for J in range(j - 1, j + 2)
                                      if I != i or J != j)
            print(ctr)
            return {ij for ij in ctr if ctr[ij] == 3 or ctr[ij] == 2 and ij in live}

        live = {(i, j) for i, row in enumerate(board) for j, live in enumerate(row) if live}
        print(live)
        live = gameOfLifeInfinite(live)
        for i, row in enumerate(board):
            for j in range(len(row)):
                row[j] = int((i, j) in live)


if __name__ == '__main__':
    m = int(input())
    board = []
    for i in range(m):
        board.append([int(num) for num in input().split()])
    solution = Solution()
    solution.gameOfLife(board)
    print(board)

