import random


class Solution:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        res = -1
        count = 0
        for i, num in enumerate(self.nums):
            if num == target:
                if random.randint(0, count) == 0:
                    res = i
                count += 1
        return res


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution(nums)
    p = int(input())
    print(solution.pick(p))
