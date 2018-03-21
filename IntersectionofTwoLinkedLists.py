class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        a = headA
        b = headB
        while a != b:
            a = headB if not a else a.next
            b = headA if not b else b.next
        return a
        
if __name__=='__main__':
    a1 = ListNode(1)
    a2 = ListNode(2)
    
    b1 = ListNode(3)
    b2 = ListNode(4)
    b3 = ListNode(5)
    
    c1 = ListNode(6)
    c2 = ListNode(7)
    c3 = ListNode(8)
    
    a1.next = a2
    a2.next = c1
    c1.next = c2
    c2.next = c3
    b1.next = b2
    b2.next = b3
    b3.next = c1
    
    solution = Solution()
    print(solution.getIntersectionNode(a1, b1).val)
