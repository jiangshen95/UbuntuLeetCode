class Solution:
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def bfs(start, dist, pre):
            visited = [False] * n
            dist[start] = 0
            pre[start] = -1
            queue = [start]
            visited[start] = True

            while queue:
                u = queue[0]
                queue.pop(0)
                for v in tree[u]:
                    if not visited[v]:
                        dist[v] = dist[u] + 1
                        pre[v] = u
                        visited[v] = True
                        queue.append(v)

        if n <= 1:
            return [0]
        tree = [[] for _ in range(n)]
        for edge in edges:
            tree[edge[0]].append(edge[1])
            tree[edge[1]].append(edge[0])

        b1 = [0] * n
        b2 = [0] * n
        pre = [0] * n

        bfs(0, b1, pre)
        u = 0
        for i in range(n):
            if b1[i] > b1[u]:
                u = i
        bfs(u, b2, pre)
        v = 0
        for i in range(n):
            if b2[i] > b2[v]:
                v = i
        longest_edge = []
        while v != -1:
            longest_edge.append(v)
            v = pre[v]

        if len(longest_edge) % 2 == 0:
            return [longest_edge[len(longest_edge) // 2 - 1], longest_edge[len(longest_edge) // 2]]
        else:
            return [longest_edge[len(longest_edge) // 2]]


if __name__ == '__main__':
    n = int(input())
    m = int(input())
    edges = []
    for i in range(m):
        edge = [int(num) for num in input().split()]
        edges.append(edge)
    solution = Solution()
    print(solution.findMinHeightTrees(n, edges))
