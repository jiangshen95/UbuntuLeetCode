import random


class Solution:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.nums

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        return random.sample(self.nums, len(self.nums))


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution(nums)
    print(solution.shuffle())
