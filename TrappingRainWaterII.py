class Solution:
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        if not heightMap:
            return 0
        m = len(heightMap)
        n = len(heightMap[0])
        if m < 3 or n < 3:
            return 0

        import heapq
        queue = []
        visited = [[False] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    heapq.heappush(queue, (heightMap[i][j], i, j))
                    visited[i][j] = True

        dir = [[0, -1], [0, 1], [-1, 0], [1, 0]]
        result = 0
        mx = 0
        while queue:
            h, x, y = heapq.heappop(queue)
            mx = max(mx, h)
            for i in range(4):
                x_ = x + dir[i][0]
                y_ = y + dir[i][1]
                if 0 <= x_ < m and 0 <= y_ < n and not visited[x_][y_]:
                    if heightMap[x_][y_] < mx:
                        result += mx - heightMap[x_][y_]
                    heapq.heappush(queue, (heightMap[x_][y_], x_, y_))
                    visited[x_][y_] = True
        return result


if __name__ == '__main__':
    m = int(input())
    heightMap = []
    for i in range(m):
        heightMap.append([int(h) for h in input().split()])
    print(heightMap)
    solution = Solution()
    print(solution.trapRainWater(heightMap))
