class Solution:
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])

        count = m * n
        res = 0
        while count > 0:
            remove = []
            for i in range(m):
                for j in range(n):
                    if matrix[i][j] == -2147483648:
                        continue
                    up = (i == 0 or (matrix[i][j] >= matrix[i - 1][j]))
                    down = (i == m - 1 or (matrix[i][j] >= matrix[i + 1][j]))
                    left = (j == 0 or (matrix[i][j] >= matrix[i][j - 1]))
                    right = (j == n - 1 or (matrix[i][j] >= matrix[i][j + 1]))

                    if up and down and left and right:
                        remove.append((i, j))
            for p in remove:
                matrix[p[0]][p[1]] = -2147483648
                count -= 1
            res += 1
        return res


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        row = [int(num) for num in input().split()]
        matrix.append(row)

    solution = Solution()
    print(solution.longestIncreasingPath(matrix))
