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
        if not root:
            return
        cur = root
        while cur.left:
            pre = cur
            while pre:
                pre.left.next = pre.right
                if pre.next:
                    pre.right.next = pre.next.left
                pre = pre.next
            cur = cur.left
