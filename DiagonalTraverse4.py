class Solution:
    def findDiagonalOrder(self, matrix: list) -> list:
        if not matrix:
            return []
        m, n = len(matrix), len(matrix[0])
        return [matrix[i][d - i] for d in range(m + n - 1) for i in range(max(0, d - n + 1), min(d + 1, m))[::d % 2 * 2 - 1]]


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append([int(num) for num in input().split()])

    solution = Solution()
    print(solution.findDiagonalOrder(matrix))
