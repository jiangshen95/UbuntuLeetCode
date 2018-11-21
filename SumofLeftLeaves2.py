class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        s = [root]
        result = 0
        while s:
            node = s.pop()
            if node.left:
                if not node.left.left and not node.left.right:
                    result += node.left.val
                else:
                    s.append(node.left)
            if node.right:
                if node.right.left or node.right.right:
                    s.append(node.right)
        return result


if __name__ == '__main__':
    a = TreeNode(3)
    b = TreeNode(9)
    c = TreeNode(20)
    d = TreeNode(15)
    e = TreeNode(7)

    a.left = b
    a.right = c
    c.left = d
    c.right = e

    solution = Solution()
    print(solution.sumOfLeftLeaves(a))
