class Solution:
    # Time Limit Exceeded
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        def dijkstra():
            dist = [1 << 30] * len(g)

            # import heapq
            # tree = []
            # heapq.heappush(tree, (0, start))
            tree = [(0, start)]

            while tree:
                # h, t = heapq.heappop(tree)
                h, t = tree.pop()
                for v, w in g[t]:
                    if max(h, w) < dist[v]:
                        if (dist[v], v) in tree:
                            tree.remove((dist[v], v))
                        dist[v] = max(h, w)
                        if (dist[v], v) not in dist:
                            tree.append((dist[v], v))
                            # heapq.heappush(tree, (dist[v], v))
            return dist

        if not heightMap:
            return 0
        m = len(heightMap)
        n = len(heightMap[0])
        if m < 3 or n < 3:
            return 0

        start = m * n
        dir = [[0, -1], [0, 1], [-1, 0], [1, 0]]
        g = [[] for _ in range(m * n + 1)]
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    g[start].append((i * n + j, 0))
                for k in range(4):
                    x, y = i + dir[k][0], j + dir[k][1]
                    if 0 <= x < m and 0 <= y < n:
                        g[i * n + j].append((x * n + y, heightMap[i][j]))
        result = 0
        dist = dijkstra()
        for i in range(m):
            for j in range(n):
                if dist[i * n + j] > heightMap[i][j]:
                    result += dist[i * n + j] - heightMap[i][j]
        return result


if __name__ == '__main__':
    m = int(input())
    heightMap = []
    for i in range(m):
        heightMap.append([int(h) for h in input().split()])
    print(heightMap)
    solution = Solution()
    print(solution.trapRainWater(heightMap))
