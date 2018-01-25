class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        if not root:
            return
        self.flatten(root.left)
        self.flatten(root.right)
        left = root.left
        right = root.right
        
        if not left:
            return
        
        root.right = left
        root.left = None
        while left.right:
            left = left.right
        left.right = right
        
if __name__=='__main__':
    root=TreeNode(1);
    a=TreeNode(2);
    b=TreeNode(3);
    c=TreeNode(4);
    d=TreeNode(5);
    e=TreeNode(6);
    
    root.left=a;
    root.right=d;
    a.left=b;
    a.right=c;
    d.right=e;
    
    solution = Solution()
    solution.flatten(root)
    
    while root:
        print(root.val)
        root = root.right
