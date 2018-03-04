class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head==None:
            return head
        front = ListNode(0)
        cur = head
        while cur:
            next = cur.next
            pre = front
            while pre.next and pre.next.val < cur.val:
                pre = pre.next
                
            cur.next = pre.next
            pre.next = cur
            cur = next
        return front.next
        
if __name__=='__main__':
    nums = list(input())
    head = ListNode(0)
    p = head
    for num in nums:
        p.next = ListNode(num)
        p = p.next
    head = head.next
    
    solution = Solution()
    p = solution.insertionSortList(head)
    
    while p:
        print(p.val)
        p = p.next

            
