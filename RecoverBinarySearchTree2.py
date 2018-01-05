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
        temp = None
        pre = None
        node1 = None
        node2 = None
        
        while cur!=None:
            if cur.left==None:
                if pre!=None and cur.val<=pre.val:
                    if node1==None:
                        node1 = pre
                        node2 = cur
                    else:
                        node2 = cur
                pre = cur
                cur = cur.right
            else:
                temp = cur.left
                while temp.right!=None and temp.right!=cur:
                    temp = temp.right
                if temp.right==None:
                    temp.right = cur
                    cur = cur.left
                elif temp.right==cur:
                    temp.right = None
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
