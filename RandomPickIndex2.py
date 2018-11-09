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
        return random.choice([k for k, v in enumerate(self.nums) if v == target])


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution(nums)
    p = int(input())
    print(solution.pick(p))
