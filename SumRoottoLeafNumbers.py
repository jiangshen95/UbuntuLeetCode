class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def sumNumbers(root, s):
            if not root:
                return 0
            if not root.left and not root.right:
                return s*10+root.val
            return sumNumbers(root.left, s*10+root.val) + sumNumbers(root.right, s*10+root.val)
        return sumNumbers(root, 0)
        
if __name__=='__main__':
    root = TreeNode(1)
    a = TreeNode(2)
    b = TreeNode(3)
    root.left = a
    root.right = b
    solution = Solution()
    print(solution.sumNumbers(root))
