class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        def levelOrder_Bottom(result, root, level):
            if root==None:
                return
            if len(result)<=level:
                result.insert(0, [])
            levelOrder_Bottom(result, root.left, level+1)
            levelOrder_Bottom(result, root.right, level+1)
            result[len(result)-level-1].append(root.val)
            
        result = []
        levelOrder_Bottom(result, root, 0)
        
        return result

if __name__=='__main__':
    root = TreeNode(3)
    a = TreeNode(9)
    b = TreeNode(20)
    c = TreeNode(15)
    d = TreeNode(7)
    
    root.left=a
    root.right=b
    b.left=c
    b.right=d
    
    solution = Solution()
    result = solution.levelOrderBottom(root)
    print(result)
