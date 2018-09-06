class Solution:
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        def longestIncreasingPath(x, y):
            if cache[x][y] > 0:
                return cache[x][y]
            m_len = 1
            for d in dir:
                if 0 <= x + d[0] < m and 0 <= y + d[1] < n and matrix[x][y] < matrix[x + d[0]][y + d[1]]:
                    m_len = max(m_len, longestIncreasingPath(x + d[0], y + d[1]) + 1)
            cache[x][y] = m_len
            return m_len

        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])

        dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]

        cache = [[0] * n for _ in range(m)]
        max_len = 1
        for i in range(m):
            for j in range(n):
                max_len = max(max_len, longestIncreasingPath(i, j))

        return max_len


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        row = [int(num) for num in input().split()]
        matrix.append(row)

    solution = Solution()
    print(solution.longestIncreasingPath(matrix))
