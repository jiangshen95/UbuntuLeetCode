class NumMatrix:

    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        m = len(matrix)
        if m == 0:
            return
        n = len(matrix[0])
        self.sums = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            for j in range(n):
                self.sums[i + 1][j + 1] = self.sums[i + 1][j] + self.sums[i][j + 1] +\
                                          matrix[i][j] - self.sums[i][j]

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        return self.sums[row2 + 1][col2 + 1] - self.sums[row2 + 1][col1] -\
               self.sums[row1][col2 + 1] + self.sums[row1][col1]


if __name__ == '__main__':
    matrix = [
        [3, 0, 1, 4, 2],
        [5, 6, 3, 2, 1],
        [1, 2, 0, 1, 5],
        [4, 1, 0, 1, 7],
        [1, 0, 3, 0, 5]
    ]
    c = NumMatrix(matrix)
    print(c.sumRegion(2, 1, 4, 3))
    print(c.sumRegion(1, 1, 2, 2))
    print(c.sumRegion(1, 2, 2, 4))
