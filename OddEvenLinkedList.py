class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        odd = head
        even = head.next
        even_head = head.next
        while odd.next and even.next:
            odd.next = odd.next.next
            even.next = even.next.next
            odd = odd.next
            even = even.next
        odd.next = even_head
        return head


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    head = ListNode(0)
    p = head
    for num in nums:
        p.next = ListNode(num)
        p = p.next
    head = head.next
    solution = Solution()
    head = solution.oddEvenList(head)
    while head:
        print(head.val)
        head = head.next
