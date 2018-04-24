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
        def reverse(head, newHead):
            if head == None:
                return newHead
            next = head.next
            head.next = newHead
            return reverse(next, head)
        return reverse(head, None)
        
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
