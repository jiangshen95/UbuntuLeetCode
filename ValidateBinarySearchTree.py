class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        stack = []
        pre = None
        
        while root!=None or len(stack)!=0:
            while root!=None:
                stack.append(root)
                root=root.left
            root = stack.pop()
            if pre!=None and root.val<=pre.val:
                return False
            pre = root
            root = root.right
        return True
        
if __name__=='__main__':
    root = TreeNode(10);
    a = TreeNode(5);
    b = TreeNode(15);
    c = TreeNode(6);
    d = TreeNode(20);
    root.left = a
    root.right = b
    b.left = c
    b.right = d
    
    solution = Solution()
    print(solution.isValidBST(root))
