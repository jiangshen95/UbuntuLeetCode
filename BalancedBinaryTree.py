class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def getDepth(root):
            if root==None:
                return 0
            ldepth = getDepth(root.left)
            if ldepth==-1:
                return -1
            rdepth = getDepth(root.right)
            if rdepth==-1:
                return -1
            if abs(ldepth-rdepth)>1:
                return -1
            return max(ldepth, rdepth)+1
            
        return getDepth(root)!=-1

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
    c.left=e;
    
    solution = Solution()
    print(solution.isBalanced(root))
