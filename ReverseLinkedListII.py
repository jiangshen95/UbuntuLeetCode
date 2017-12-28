class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        p = ListNode(0)
        p.next = head
        head = p
        
        for i in range(m-1):
            p = p.next
        begin = p
        p = p.next
        q = p.next
        for i in range(n-m):
            p.next = q.next
            q.next = begin.next
            begin.next = q
            q = p.next
        
        return head.next
        
if __name__=='__main__':
    nums = list(input())
    head = ListNode(0)
    p = head
    for i in nums:
        q = ListNode(i)
        p.next = q
        p = q
    head = head.next
    
    m = int(raw_input())
    n = int(raw_input())
    
    solution = Solution()
    head = solution.reverseBetween(head, m, n)
    
    while head!=None:
        print(head.val)
        head = head.next
        
