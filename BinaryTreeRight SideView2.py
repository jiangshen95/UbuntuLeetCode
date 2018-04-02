class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        if not root:
            return result
        nodes = [root]
        while nodes:
            result.append(nodes[-1].val)
            nodes = [kid for node in nodes for kid in (node.left, node.right) if kid]
        return result
        
if __name__ == '__main__':
    a = TreeNode(1)
    b = TreeNode(2)
    c = TreeNode(3)
    d = TreeNode(4)
    e = TreeNode(5)
    
    a.left = b
    a.right = c
    b.right = e
    c.right = d
    
    solution = Solution()
    print(solution.rightSideView(a))
