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
        def rightSideView(root, result, depth):
            if not root:
                return
            if depth == len(result):
                result.append(root.val);
            rightSideView(root.right, result, depth + 1)
            rightSideView(root.left, result, depth + 1)
        result = []
        rightSideView(root, result, 0)
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
