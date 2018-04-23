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
        # RecursionError: maximum recursion depth exceeded in comparison
        if head == None:
            return None
        head.next = self.removeElements(head.next, val)
        return head.next if head.val == val else head
        
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
