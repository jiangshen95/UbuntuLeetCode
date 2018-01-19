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
        
        i = 0
        j = 0
        
        isright = False
        
        stack = []
        
        root = TreeNode(preorder[i])
        t = root
        stack.append(t)
        i += 1
        
        while i<len(preorder):
            if len(stack)>0 and stack[-1].val==inorder[j]:
                t = stack.pop()
                isright = True
                j += 1
            else:
                if isright:
                    t.right = TreeNode(preorder[i])
                    t = t.right
                    stack.append(t)
                    i += 1
                    isright = False
                else:
                    t.left = TreeNode(preorder[i])
                    t = t.left
                    stack.append(t)
                    i += 1
        
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
