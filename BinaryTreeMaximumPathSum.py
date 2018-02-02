class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def maxPath(root):
            if not root:
                return 0
            lmax = maxPath(root.left)
            rmax = maxPath(root.right)
            self.res = max(self.res, lmax+rmax+root.val)
            return max(max(lmax, rmax)+root.val, 0)
        self.res = -10000000
        maxPath(root)
        return self.res
        
if __name__=='__main__':
    root=TreeNode(1);
    a=TreeNode(2);
    b=TreeNode(3);
    c=TreeNode(4);
    d=TreeNode(5);
    e=TreeNode(6);
    f=TreeNode(7);
    
    root.left=a;
    root.right=b;
    a.eft=c;
    a.right=d;
    b.left=e;
    b.right=f;
    
    solution = Solution()
    print(solution.maxPathSum(root))
