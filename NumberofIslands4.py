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
        rightDepthValue = {}
        nodeStack = [(root, 0)]
        max_depth = -1
        while nodeStack:
            node = nodeStack[-1][0]
            depth = nodeStack[-1][1]
            nodeStack.pop()
            if node:
                max_depth = max(max_depth, depth)
                if depth not in rightDepthValue:
                    rightDepthValue[depth] = node.val
                nodeStack.append((node.left, depth + 1))
                nodeStack.append((node.right, depth + 1))
        for i in range(max_depth + 1):
            result.append(rightDepthValue[i])
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
