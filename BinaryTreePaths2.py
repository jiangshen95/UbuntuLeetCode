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
        if not root.left and not root.right:
            return [str(root.val)]
        for path in self.binaryTreePaths(root.left):
            paths.append(str(root.val) + '->' + path)
        for path in self.binaryTreePaths(root.right):
            paths.append(str(root.val) + '->' + path)
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
