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
        result = self.nums[:]
        for i in range(len(result)):
            r = random.randint(i, len(result) - 1)
            result[i], result[r] = result[r], result[i]
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution(nums)
    print(solution.shuffle())
