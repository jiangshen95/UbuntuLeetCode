class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None
        
class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        cur = root
        while cur:
            dummy = TreeLinkNode(0)
            p = dummy
            while cur:
                if cur.left:
                    p.next = cur.left
                    p = p.next
                if cur.right:
                    p.next = cur.right
                    p = p.next
                cur = cur.next
            cur = dummy.next
            
