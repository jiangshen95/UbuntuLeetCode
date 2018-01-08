class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def is_symmetric(l, r):
            if l==None and r==None:
                return True
            if l==None or r==None:
                return False
            if l.val!=r.val:
                return False
            return is_symmetric(l.left, r.right) and is_symmetric(l.right, r.left)
            
        if root==None:
            return True
        return is_symmetric(root.left, root.right)

if __name__=='__main__':
    root = TreeNode(1);
    a = TreeNode(2);
    b = TreeNode(2);
    c = TreeNode(3);
    d = TreeNode(4);
    e = TreeNode(4);
    f = TreeNode(3);
    root.left=a;
    root.right=b;
    a.left=c;
    a.right=d;
    b.left=e;
    b.right=f;
    
    solution = Solution()
    print(solution.isSymmetric(root))
