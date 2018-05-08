class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return root
        nodes = [root]
        while len(nodes) > 0:
            node = nodes.pop()
            if node:
                nodes.append(node.left)
                nodes.append(node.right)
                node.left, node.right = node.right, node.left
        return root
        
    def printTree(self, root):
        if root:
            print(root.val)
            self.printTree(root.left)
            self.printTree(root.right)

if __name__ == '__main__':
    
    a = TreeNode(4)
    b = TreeNode(2)
    c = TreeNode(7)
    d = TreeNode(1)
    e = TreeNode(3)
    f = TreeNode(6)
    g = TreeNode(9)
    
    a.left = b
    a.right = c
    b.left = d
    b.right = e
    c.left = f
    c.right = g
    
    solution = Solution()
    solution.printTree(a)
    solution.printTree(solution.invertTree(a))
