class Solution:
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        def dfs(x, y, visited, pre):
            if x < 0 or x >= m or y < 0 or y >= n or visited[x][y] or matrix[x][y] < pre:
                return
            visited[x][y] = True
            dfs(x - 1, y, visited, matrix[x][y])
            dfs(x + 1, y, visited, matrix[x][y])
            dfs(x, y - 1, visited, matrix[x][y])
            dfs(x, y + 1, visited, matrix[x][y])
        if not matrix:
            return []
        m = len(matrix)
        n = len(matrix[0])

        pacific = [[False] * n for _ in range(m)]
        atlantic = [[False] * n for _ in range(m)]
        for i in range(m):
            dfs(i, 0, pacific, -1)
            dfs(i, n - 1, atlantic, -1)
        for i in range(n):
            dfs(0, i, pacific, -1)
            dfs(m - 1, i, atlantic, -1)

        result = []
        for i in range(m):
            for j in range(n):
                if pacific[i][j] and atlantic[i][j]:
                    result.append([i, j])
        return result


if __name__ == '__main__':
    m = int(input())
    matrix = []
    for i in range(m):
        matrix.append([int(num) for num in input().split()])
    solution = Solution()
    print(solution.pacificAtlantic(matrix))
