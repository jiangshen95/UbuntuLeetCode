class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root==None:
            return False
        if root.left==None and root.right==None:
            return sum==root.val
        return self.hasPathSum(root.left, sum-root.val) or self.hasPathSum(root.right, sum-root.val)
        
if __name__=='__main__':
    root=TreeNode(5);
    a=TreeNode(4);
    b=TreeNode(8);
    c=TreeNode(11);
    d=TreeNode(13);
    e=TreeNode(4);
    f=TreeNode(7);
    g=TreeNode(2);
    h=TreeNode(1);
    
    root.left=a;
    root.right=b;
    a.left=c;
    b.left=d;
    b.right=e;
    c.left=f;
    c.right=g;
    e.right=h;
    
    sum = int(raw_input())
    
    solution = Solution()
    print(solution.hasPathSum(root, sum))
