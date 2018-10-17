import random


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:

    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.head = head

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        before = 0
        buffer = [0] * 100
        node = self.head
        res = self.head.val
        while node:
            i = 0
            while node and i < 100:
                buffer[i] = node.val
                i += 1
                node = node.next
            rindex = random.randint(0, before + i - 1)
            if rindex < i:
                res = buffer[rindex]
            before += i
        return res


if __name__ == '__main__':
    a = ListNode(1)
    a.next = ListNode(2)
    a.next.next = ListNode(3)

    solution = Solution(a)
    print(solution.getRandom())
    print(solution.getRandom())
    print(solution.getRandom())
