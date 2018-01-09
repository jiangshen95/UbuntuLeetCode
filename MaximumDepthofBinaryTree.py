class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root==None:
            return 0
        depthl = self.maxDepth(root.left) + 1
        depthr = self.maxDepth(root.right) + 1
        return max(depthl, depthr)
        
if __name__=='__main__':
    root = TreeNode(1)
    a = TreeNode(2)
    b = TreeNode(3)
    root.left=a
    a.left=b
    
    solution = Solution()
    print(solution.maxDepth(root))
