class Solution:
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        if n <= 1:
            return [0]
        tree = [[] for _ in range(n)]
        for edge in edges:
            tree[edge[0]].append(edge[1])
            tree[edge[1]].append(edge[0])

        leaves = []
        for i in range(n):
            if len(tree[i]) == 1:
                leaves.append(i)

        while n > 2:
            size = len(leaves)
            n -= size
            newLeaves = []
            for leaf in leaves:
                t = tree[leaf][0]
                for i in range(len(tree[t])):
                    if tree[t][i] == leaf:
                        tree[t].pop(i)
                        if len(tree[t]) == 1:
                            newLeaves.append(t)
                        break
            leaves = newLeaves
        return leaves


if __name__ == '__main__':
    n = int(input())
    m = int(input())
    edges = []
    for i in range(m):
        edge = [int(num) for num in input().split()]
        edges.append(edge)
    solution = Solution()
    print(solution.findMinHeightTrees(n, edges))
