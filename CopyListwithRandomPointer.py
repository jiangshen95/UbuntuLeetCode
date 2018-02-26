class RandomListNode(object):
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None
        
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        cur = head
        while cur:
            next = cur.next
            copy = RandomListNode(cur.label)
            cur.next = copy
            copy.next = next
            cur = next
        cur = head
        while cur:
            if cur.random:
                cur.next.random = cur.random.next
            cur = cur.next.next
        front = RandomListNode(0)
        copy = front
        cur = head
        while cur:
            copy.next = cur.next
            copy = copy.next
            cur.next = cur.next.next
            cur = cur.next
        return front.next
