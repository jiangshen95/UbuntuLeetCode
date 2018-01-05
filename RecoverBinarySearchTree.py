class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        stack = []
        cur = root
        pre = None
        node1 = None
        node2 = None
        
        while cur!=None or len(stack)!=0:
            while cur!=None:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            if pre!=None and cur.val<=pre.val:
                if node1==None:
                    node1 = pre
                    node2 = cur
                else:
                    node2 = cur
            pre = cur
            cur = cur.right
        t = node1.val
        node1.val = node2.val
        node2.val = t
        
    def printTree(self, root):
        if root!=None:
            print(root.val)
            self.printTree(root.left)
            self.printTree(root.right)
        
if __name__=='__main__':
    root = TreeNode(2)
    a = TreeNode(1)
    b = TreeNode(3)
    root.left = b
    root.right = a
    
    solution = Solution()
    solution.recoverTree(root)
    solution.printTree(root)
