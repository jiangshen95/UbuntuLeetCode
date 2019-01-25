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

        def addToFront(val, head):
            cur = ListNode(val)
            cur.next = head
            return cur

        n1, n2 = getLength(l1), getLength(l2)
        result = None
        while n1 > 0 and n2 > 0:
            val = 0
            if n1 >= n2:
                val += l1.val
                l1 = l1.next
                n1 -= 1
            if n1 < n2:
                val += l2.val
                l2 = l2.next
                n2 -= 1
            result = addToFront(val, result)

        cur, result = result, None
        carry = 0
        while cur:
            carry += cur.val
            result = addToFront(carry % 10, result)
            carry //= 10
            cur = cur.next
        if carry > 0:
            result = addToFront(carry, result)
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
