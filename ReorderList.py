class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if head == None or head.next == None:
            return
        p = head
        q = head
        while q.next and q.next.next:
            p = p.next
            q = q.next.next
        mid = p
        
        p = mid
        q = mid.next
        while q.next:
            cur = q.next
            q.next = cur.next
            cur.next = p.next
            p.next = cur
            
        p = head
        q = mid.next
        while p!=mid:
            mid.next = q.next
            q.next = p.next
            p.next = q
            p = q.next
            q = mid.next

if __name__=='__main__':
    nums = list(input())
    head = ListNode(0)
    p = head
    for num in nums:
        p.next = ListNode(num)
        p = p.next
    head = head.next
    
    solution = Solution()
    solution.reorderList(head)
    
    p = head
    while p:
        print(p.val)
        p = p.next
