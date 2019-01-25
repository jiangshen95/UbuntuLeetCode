class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        s1, s2 = [], []
        while l1:
            s1.append(l1.val)
            l1 = l1.next
        while l2:
            s2.append(l2.val)
            l2 = l2.next

        result = None
        carry = 0
        while s1 or s2:
            if s1:
                carry += s1.pop()
            if s2:
                carry += s2.pop()
            head = ListNode(carry % 10)
            head.next = result
            result = head
            carry //= 10
        if carry > 0:
            head = ListNode(carry)
            head.next = result
            result = head
        return result


if __name__ == '__main__':
    nums1 = [int(num) for num in input().split()]
    nums2 = [int(num) for num in input().split()]

    l1 = ListNode(0)
    cur = l1
    for num in nums1:
        cur.next = ListNode(num)
        cur = cur.next
    l1 = l1.next

    l2 = ListNode(0)
    cur = l2
    for num in nums2:
        cur.next = ListNode(num)
        cur = cur.next
    l2 = l2.next

    solution = Solution()
    result = solution.addTwoNumbers(l1, l2)
    while result:
        print(result.val)
        result = result.next
