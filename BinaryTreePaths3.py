class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if not root:
            return []
        paths = []
        stack = []
        stack.append((root, ''))
        while stack:
            cur, path = stack[-1]
            stack.pop()
            if not cur.left and not cur.right:
                paths.append(path + str(cur.val))
            if cur.right:
                stack.append((cur.right, path + str(cur.val) + '->'))
            if cur.left:
                stack.append((cur.left, path + str(cur.val) + '->'))
        return paths

if __name__ == '__main__':
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(5)

    a.left = b
    a.right = c
    b.right = d

    solution = Solution()
    print(solution.binaryTreePaths(a))
