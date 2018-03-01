class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        preorder = []
        if root==None:
            return preorder
        stack = [root]
        while stack:
            cur = stack.pop()
            preorder.append(cur.val)
            if cur.right:
                stack.append(cur.right)
            if cur.left:
                stack.append(cur.left)
        return preorder

if __name__=='__main__':
    a = TreeNode(1);
    b = TreeNode(2);
    c = TreeNode(3);
    d = TreeNode(4);
    e = TreeNode(5);
    
    a.left = b;
    a.right = c;
    b.left = d;
    d.right = e;
    
    solution = Solution()
    print(solution.preorderTraversal(a))
