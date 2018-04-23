class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        
class Solution:
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        while head and head.val == val:
            head = head.next
        cur = head
        while cur and cur.next:
            if cur.next.val == val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head
        
if __name__=='__main__':
    nums = list(input())
    head = ListNode(0)
    cur = head
    for num in nums:
        cur.next = ListNode(num)
        cur = cur.next
    head = head.next
    val = int(raw_input())
    solution = Solution()
    head = solution.removeElements(head, val)
    while head:
        print(head.val)
        head = head.next
