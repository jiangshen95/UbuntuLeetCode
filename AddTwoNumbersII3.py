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

        def addTwoNumbers(l1, l2, diff):
            if not l1 or not l2:
                return None

            result = ListNode(0)
            if diff > 0:
                result.val = l1.val
                result.next = addTwoNumbers(l1.next, l2, diff - 1)
            else:
                result.val = l1.val + l2.val
                result.next = addTwoNumbers(l1.next, l2.next, diff)
            if result.next:
                result.val += result.next.val // 10
                result.next.val %= 10
            return result

        n1, n2 = getLength(l1), getLength(l2)
        if n1 < n2:
            l1, l2 = l2, l1
        result = addTwoNumbers(l1, l2, abs(n1 - n2))

        if result.val > 9:
            node = ListNode(result.val // 10)
            result.val %= 10
            node.next = result
            result = node

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
