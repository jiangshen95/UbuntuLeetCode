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
        def pathSum(root, curSum, sum):
            if not root:
                return 0
            count = 0
            curSum += root.val
            count += m.get(curSum - sum, 0)

            m[curSum] = m.get(curSum, 0) + 1
            count += pathSum(root.left, curSum, sum) + pathSum(root.right, curSum, sum)
            m[curSum] -= 1
            return count

        if not root:
            return 0
        m = {0: 1}
        return pathSum(root, 0, sum)


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
