class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def merge(slef, l1, l2):
        front = ListNode(0)
        pre = front
        while l1 and l2:
            if l1.val<l2.val:
                pre.next = l1
                l1 = l1.next
            else:
                pre.next = l2
                l2 = l2.next
            pre = pre.next
        if l1:
            pre.next = l1
        if l2:
            pre.next = l2
        return front.next
        
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return head
        
        slow = head
        fast = head
        pre = head
        while fast and fast.next:
            pre = slow
            slow = slow.next
            fast = fast.next
        pre.next = None
        return self.merge(self.sortList(head), self.sortList(slow))


if __name__=='__main__':
    nums = list(input())
    head = ListNode(0)
    p = head
    for num in nums:
        p.next = ListNode(num)
        p = p.next
    head = head.next
    
    solution = Solution()
    p = solution.sortList(head)
    
    while p:
        print(p.val)
        p = p.next
