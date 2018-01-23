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
            
        i = len(postorder)-1
        j = len(inorder)-1
        
        isLeft = False
        
        stack = []
        root = TreeNode(postorder[i])
        t = root
        stack.append(t)
        i -= 1
        while i>=0:
            if len(stack)>0 and stack[-1].val==inorder[j]:
                t = stack.pop()
                isLeft = True
                j -= 1
            else:
                if isLeft:
                    t.left = TreeNode(postorder[i])
                    t = t.left
                    stack.append(t)
                    isLeft = False
                    i -= 1
                else:
                    t.right = TreeNode(postorder[i])
                    t = t.right
                    stack.append(t)
                    i -= 1
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
