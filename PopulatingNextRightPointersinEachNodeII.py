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
        dummy = TreeLinkNode(0)
        p = dummy
        while cur:
            p.next = cur.left
            if p.next:
                p = p.next
            p.next = cur.right
            if p.next:
                p = p.next
            cur = cur.next
            if cur==None:
                cur = dummy.next
                p = dummy
            
