# Time Limit Exceeded
class Solution:
    class Node:
        def __init__(self, val):
            self.val = val
            self.left = None
            self.right = None
            self.count_ge = 1

    def search(self, head, target):
        if not head:
            return 0
        if target == head.val:
            return head.count_ge
        elif target > head.val:
            return self.search(head.right, target)
        else:
            return head.count_ge + self.search(head.left, target)

    def insert(self, head, val):
        if not head:
            return self.Node(val)
        if val == head.val:
            head.count_ge += 1
        elif val > head.val:
            head.count_ge += 1
            head.right = self.insert(head.right, val)
        else:
            head.left = self.insert(head.left, val)
        return head

    def reversePairs(self, nums: list) -> int:
        head = None
        result = 0
        for num in nums:
            result += self.search(head, num * 2 + 1)
            head = self.insert(head, num)
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.reversePairs(nums))
