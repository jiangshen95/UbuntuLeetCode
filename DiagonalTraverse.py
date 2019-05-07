class Solution:
    def findDiagonalOrder(self, matrix: list) -> list:
        if not matrix:
            return []
        m, n = len(matrix), len(matrix[0])
        result = []
        for i in range(m + n - 1):
            low = max(0, i - n + 1)
            up = min(i, m - 1)
            if i % 2 == 1:
                result += [matrix[j][i - j] for j in range(low, up + 1, 1)]
            else:
                result += [matrix[j][i - j] for j in range(up, low - 1, -1)]
        return result


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append([int(num) for num in input().split()])

    solution = Solution()
    print(solution.findDiagonalOrder(matrix))
