class Solution:
    def findDiagonalOrder(self, matrix: list) -> list:
        if not matrix:
            return []
        m, n = len(matrix), len(matrix[0])
        result = []
        dirs = [[-1, 1], [1, -1]]
        r, c, k = 0, 0, 0
        for i in range(m * n):
            result.append(matrix[r][c])
            r += dirs[k][0]
            c += dirs[k][1]
            if c >= n:
                c = n - 1
                r += 2
                k = 1 - k
            if r >= m:
                r = m - 1
                c += 2
                k = 1 - k
            if c < 0:
                c = 0
                k = 1 - k
            if r < 0:
                r = 0
                k = 1 - k
        return result


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append([int(num) for num in input().split()])

    solution = Solution()
    print(solution.findDiagonalOrder(matrix))
