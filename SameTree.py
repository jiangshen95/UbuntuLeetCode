class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if p==None and q==None:
            return True
        if p==None or q==None:
            return False
        if p.val!=q.val:
            return False
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        
if __name__=='__main__':
    p = TreeNode(1);
    a = TreeNode(2);
    q = TreeNode(1);
    b = TreeNode(2);
    
    p.left = a
    p.right = b
    
    solution = Solution()
    print(solution.isSameTree(p, q))
