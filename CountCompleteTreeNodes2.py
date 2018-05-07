class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def getHeight(self, root):
        height = 0
        while root:
            height += 1
            root = root.left
        return height
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        deepl = self.getHeight(root.left)
        deepr = self.getHeight(root.right)
        if deepl == deepr:
            return (1 << deepl) + self.countNodes(root.right)
        else:
            return (1 << deepr) + self.countNodes(root.left)
            
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
