class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root==None:
            return 0
        ldepth = self.minDepth(root.left)
        rdepth = self.minDepth(root.right)
        return max(ldepth, rdepth)+1 if ldepth==0 or rdepth==0 else min(ldepth, rdepth)+1
        
if __name__=='__main__':
    root=TreeNode(1);
    a=TreeNode(2);
    b=TreeNode(3);
    c=TreeNode(4);
    d=TreeNode(5);
    e=TreeNode(6);
    
    root.left=a;
    root.right=b;
    a.left=c;
    a.right=d;
    b.left=e;
    
    solution = Solution()
    print(solution.minDepth(root))
