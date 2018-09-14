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
                return [0, 0]
            left = rob(root.left)
            right = rob(root.right)
            result = [0, 0]
            result[0] = max(left[0], left[1]) + max(right[0], right[1])
            result[1] = root.val + left[0] + right[0]
            return result

        result = rob(root)
        return max(result[0], result[1])


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
