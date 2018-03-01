class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        postorder = []
        if root == None:
            return postorder
        postorder += self.postorderTraversal(root.left) + self.postorderTraversal(root.right) + [root.val]
        return postorder
        
if __name__=='__main__':
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(4)
    e = TreeNode(5)
    
    a.left = b;
    a.right = c;
    b.left = d;
    d.right = e;
    
    solution = Solution()
    print(solution.postorderTraversal(a))
