class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def rob(root):
            if not root:
                return 0
            if root in m:
                return m[root]
            val = root.val
            if root.left:
                val += rob(root.left.left) + rob(root.left.right)
            if root.right:
                val += rob(root.right.left) + rob(root.right.right)
            return max(val, rob(root.left) + rob(root.right))
        m = {}
        return rob(root)


if __name__ == '__main__':
    a = TreeNode(3)
    b = TreeNode(4)
    c = TreeNode(5)
    d = TreeNode(1)
    e = TreeNode(3)
    f = TreeNode(1)

    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.right = f

    solution = Solution()
    print(solution.rob(a))
