class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        h1 = ListNode(0)
        h2 = ListNode(0)
        
        p = h1
        q = h2
        
        while head!=None:
            if head.val<x:
                p.next = head
                p = p.next
            else:
                q.next = head
                q = q.next
            head = head.next
        q.next = None
        p.next = h2.next
        
        return h1.next
        
if __name__=='__main__':
    nums = list(input())
    head = ListNode(0)
    p = head
    for num in nums:
        q = ListNode(num)
        p.next = q
        p = q
    head = head.next
    
    x = int(input())
    solution = Solution()
    head = solution.partition(head, x)
    
    while head!=None:
        print(head.val)
        head=head.next
