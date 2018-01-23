class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        
class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(inorder)==0:
            return None
        root = TreeNode(postorder[len(postorder)-1])
        where = 0
        for i in range(len(inorder)):
            if inorder[i] == postorder[len(postorder)-1]:
                where = i
                break
        root.left = self.buildTree(inorder[0:where], postorder[0:where])
        root.right = self.buildTree(inorder[where+1:], postorder[where:-1])
        
        return root
        
    def printTree(self, root):
        if root!=None:
            print(root.val)
            self.printTree(root.left)
            self.printTree(root.right)
        
if __name__=='__main__':
    inorder = list(input())
    postorder = list(input())
    
    solution = Solution()
    root = solution.buildTree(inorder, postorder)
    solution.printTree(root)
