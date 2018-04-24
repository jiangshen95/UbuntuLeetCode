class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = None
        cur = head
        while cur:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        return pre
        
if __name__=='__main__':
    nums = list(input())
    head = ListNode(0)
    cur = head
    for num in nums:
        cur.next = ListNode(num)
        cur = cur.next
    head = head.next
    solution = Solution()
    head = solution.reverseList(head)
    while head:
        print(head.val)
        head = head.next
