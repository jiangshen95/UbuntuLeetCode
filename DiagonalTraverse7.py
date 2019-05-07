class Solution:
    def findDiagonalOrder(self, matrix: list) -> list:
        if not matrix:
            return []
        m, n = len(matrix), len(matrix[0])
        l = [[i, j] for i in range(m) for j in range(n)]
        l.sort(key=lambda x: float(x[0] + x[1]) - float(x[(x[0] + x[1]) % 2]) * 0.000000001)
        return [matrix[x][y] for x, y in l]


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append([int(num) for num in input().split()])

    solution = Solution()
    print(solution.findDiagonalOrder(matrix))
