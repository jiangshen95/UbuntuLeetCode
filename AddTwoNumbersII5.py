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
        def getNum(head):
            num = 0
            while head:
                num = num * 10 + head.val
                head = head.next
            return num

        num1 = getNum(l1)
        num2 = getNum(l2)
        sum_num = num1 + num2
        sum_num = str(sum_num)
        result = ListNode(0)
        cur = result
        for n in sum_num:
            cur.next = ListNode(int(n))
            cur = cur.next
        return result.next


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
