class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        if root==None:
            return result
        if root.left!=None:
            result = self.inorderTraversal(root.left) + result
        result.append(root.val)
        if root.right!=None:
            result = result + self.inorderTraversal(root.right)
        return result
        
if __name__=='__main__':
    root = TreeNode(1)
    p = TreeNode(2)
    root.right = p
    q = TreeNode(3)
    p.left = q
    
    solution = Solution()
    result = solution.inorderTraversal(root)
    print(result)
