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
        def is_validBST(root, minNode, maxNode):
            if root==None:
                return True
            if (minNode!=None and root.val<=minNode.val) or (maxNode!=None and root.val>=maxNode.val):
                return False
            return is_validBST(root.left, minNode, root) and is_validBST(root.right, root, maxNode)
        return is_validBST(root, None, None)
        
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
