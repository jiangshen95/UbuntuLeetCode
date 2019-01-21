class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        def helper(cur, origin, targets):
            if not cur:
                return 0
            count = 0
            for t in targets:
                if t - cur.val == 0:
                    count += 1
            targets = [t - cur.val for t in targets] + [origin]
            return count + helper(cur.left, origin, targets) + helper(cur.right, origin, targets)

        return helper(root, sum, [sum])


if __name__ == '__main__':
    a = TreeNode(10)
    b = TreeNode(5)
    c = TreeNode(-3)
    d = TreeNode(3)
    e = TreeNode(2)
    f = TreeNode(11)
    g = TreeNode(3)
    h = TreeNode(-2)
    i = TreeNode(1)

    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.right = f
    d.left = g
    d.right = h
    e.right = i

    solution = Solution()
    print(solution.pathSum(a, 8))
