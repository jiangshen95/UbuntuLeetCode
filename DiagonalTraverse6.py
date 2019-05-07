class Solution:
    def findDiagonalOrder(self, matrix: list) -> list:
        if not matrix:
            return []
        m, n = len(matrix), len(matrix[0])
        entries = [[] for _ in range(m + n - 1)]
        for i in range(m):
            for j in range(n):
                entries[i + j].append(matrix[i][j])
        result = []
        for i in range(len(entries)):
            result += entries[i][::i % 2 * 2 - 1]
        return result


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append([int(num) for num in input().split()])

    solution = Solution()
    print(solution.findDiagonalOrder(matrix))
