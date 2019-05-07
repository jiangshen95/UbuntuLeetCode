class Solution:
    def findDiagonalOrder(self, matrix: list) -> list:
        if not matrix:
            return []
        entries = [(i + j, (j, i)[(i ^ j) & 1], val) for i, row in enumerate(matrix) for j, val in enumerate(row)]
        return [e[2] for e in sorted(entries)]


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append([int(num) for num in input().split()])

    solution = Solution()
    print(solution.findDiagonalOrder(matrix))
