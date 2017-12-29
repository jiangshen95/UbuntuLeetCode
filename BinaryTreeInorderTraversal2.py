class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        
        curr = root
        stack = []
        while curr!=None or len(stack)!=0:
            while curr!=None:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            result.append(curr.val)
            curr = curr.right
        return result
        
        
if __name__=='__main__':
    root = TreeNode(1)
    p = TreeNode(2)
    root.right = p
    q = TreeNode(3)
    p.left = q
    
    solution = Solution()
    result = solution.inorderTraversal(root)
    print(result)
