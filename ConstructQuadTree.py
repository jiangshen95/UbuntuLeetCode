class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight


class Solution:
    def construct(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: Node
        """
        n = len(grid)
        s = sum(sum(row) for row in grid)
        if s == 0:
            return Node(False, True, None, None, None, None)
        elif s == n * n:
            return Node(True, True, None, None, None, None)
        else:
            return Node(True, False, self.construct([row[: n // 2] for row in grid[: n // 2]]),
                        self.construct([row[n // 2:] for row in grid[: n // 2]]),
                        self.construct([row[: n // 2] for row in grid[n // 2:]]),
                        self.construct([row[n // 2:] for row in grid[n // 2:]]))
