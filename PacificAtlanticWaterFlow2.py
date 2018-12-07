class Solution:
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        def bfs(q, place):
            dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]
            while q:
                x, y = q.pop(0)
                place[x][y] = True
                for d1, d2 in dir:
                    x_ = x + d1
                    y_ = y + d2
                    if 0 <= x_ < m and 0 <= y_ < n and not place[x_][y_] and matrix[x_][y_] >= matrix[x][y]:
                        q.append((x_, y_))

        if not matrix:
            return []
        m = len(matrix)
        n = len(matrix[0])

        pacific = [[False] * n for _ in range(m)]
        atlantic = [[False] * n for _ in range(m)]
        q1, q2 = [], []
        for i in range(m):
            q1.append((i, 0))
            q2.append((i, n - 1))
        for i in range(n):
            q1.append((0, i))
            q2.append((m - 1, i))

        bfs(q1, pacific)
        bfs(q2, atlantic)
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
