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
        def getLength(head):
            l = 0
            while head:
                l += 1
                head = head.next
            return l

        n1, n2 = getLength(l1), getLength(l2)
        if n1 < n2:
            l1, l2 = l2, l1
        diff = abs(n1 - n2)

        dummy = ListNode(0)
        cur, right = dummy, dummy
        while diff > 0:
            cur.next = ListNode(l1.val)
            if l1.val != 9:
                right = cur.next
            l1 = l1.next
            cur = cur.next
            diff -= 1

        while l1:
            val = l1.val + l2.val
            if val >= 10:
                right.val += 1
                while right.next:
                    right.next.val = 0
                    right = right.next
                right = cur
            cur.next = ListNode(val % 10)
            if cur.next.val != 9:
                right = cur.next
            cur = cur.next
            l1 = l1.next
            l2 = l2.next
        return dummy if dummy.val > 0 else dummy.next


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
