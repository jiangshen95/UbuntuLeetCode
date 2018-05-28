class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        p = head
        cur = head
        pre = None
        while p and p.next:
            p = p.next.next
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        if p:
            cur = cur.next

        while pre and cur:
            if pre.val != cur.val:
                return False
            pre = pre.next
            cur = cur.next
        return True

if __name__ == '__main__':
    str_in = input()
    nums = [int(n) for n in str_in.split()]
    head = ListNode(0)
    p = head
    for num in nums:
        p.next = ListNode(num)
        p = p.next
    head = head.next
    solution = Solution()
    print(solution.isPalindrome(head))