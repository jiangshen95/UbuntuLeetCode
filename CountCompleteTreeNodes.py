class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        deepl = 0
        deepr = 0
        cur = root
        while cur:
            deepl += 1
            cur = cur.left
        cur = root
        while cur:
            deepr += 1
            cur = cur.right
        if deepl == deepr:
            return (1 << deepl) - 1
        else:
            return self.countNodes(root.left) + self.countNodes(root.right) + 1
            
if __name__ == '__main__':
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(4)
    e = TreeNode(5)
    f = TreeNode(6)
    
    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.left = f
    
    solution = Solution()
    print(solution.countNodes(a))
