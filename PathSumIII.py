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
        if not root:
            return 0
        return self.pathSum(root.left, sum) + self.pathSum(root.right, sum) + self.sumUp(root, sum)

    def sumUp(self, root, sum):
        if not root:
            return 0
        return (sum == root.val) + self.sumUp(root.left, sum - root.val) + self.sumUp(root.right, sum - root.val)


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
