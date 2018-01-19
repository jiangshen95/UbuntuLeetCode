class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(preorder)==0:
            return None
        root = TreeNode(preorder[0])
        where = 0
        for i in range(len(inorder)):
            if inorder[i] == preorder[0]:
                where = i
                break
        root.left = self.buildTree(preorder[1:where+1], inorder[0:where])
        root.right = self.buildTree(preorder[where+1:], inorder[where+1:])
        
        return root
        
    def printTree(self, root):
        if root!=None:
            print(root.val)
            self.printTree(root.left)
            self.printTree(root.right)
        
if __name__=='__main__':
    preorder = list(input())
    inorder = list(input())
    
    solution = Solution()
    root = solution.buildTree(preorder, inorder)
    solution.printTree(root)
