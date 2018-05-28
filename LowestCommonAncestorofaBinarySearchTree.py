class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        while (root.val - p.val) * (root.val - q.val) > 0:
            root = root.left if root.val > p.val else root.right
        return root

if __name__ == '__main__':
    a = TreeNode(6)
    b = TreeNode(2)
    c = TreeNode(8)
    d = TreeNode(0)
    e = TreeNode(4)
    f = TreeNode(7)
    g = TreeNode(9)
    h = TreeNode(3)
    i = TreeNode(5)

    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.left = f
    c.right = g
    e.left = h
    e.right = i

    solution = Solution()
    print(solution.lowestCommonAncestor(a, b, c).val)