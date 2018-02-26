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
        if head==None:
            return None
        l1 = head
        while l1:
            l2 = RandomListNode(l1.label)
            l2.next = l1.random
            l1.random = l2
            l1 = l1.next
        l1 = head
        copy = head.random
        while l1:
            l2 = l1.random
            if l2.next:
                l2.random = l2.next.random
            else:
                l2.random = None
            l1 = l1.next
        l1 = head
        while l1:
            l2 = l1.random
            l1.random = l2.next
            if l1.next:
                l2.next = l1.next.random
            else:
                l2.next = None
            l1 = l1.next
        return copy
