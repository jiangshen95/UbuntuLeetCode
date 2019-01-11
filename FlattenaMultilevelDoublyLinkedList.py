class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        cur = head
        while cur:
            if cur.child:
               child = cur.child
               next = cur.next
               cur.next = child
               child.prev = cur
               while child.next:
                   child = child.next
               child.next = next
               if next:
                   next.prev = child
               cur.child = None
            cur = cur.next
        return head

