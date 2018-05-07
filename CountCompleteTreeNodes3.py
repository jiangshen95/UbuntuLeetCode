class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def countLastLevel(self, root, height):
        if height == 1:
            if root.right:
                return 2
            elif root.left:
                return 1
            else:
                return 0
        midNode = root.left
        for i in range(height - 1):
            midNode = midNode.right
        if midNode:
            return (1 << (height - 1)) + self.countLastLevel(root.right, height - 1)
        else:
            return self.countLastLevel(root.left, height - 1)
        
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        if not root.left:
            return 1
        height = 0
        cur = root
        while cur:
            height += 1
            cur = cur.left
        height -= 1
        return (1 << height) - 1 + self.countLastLevel(root, height)
            
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
