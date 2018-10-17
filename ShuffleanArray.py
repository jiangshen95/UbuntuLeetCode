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
        temp = self.nums[:]
        result = [0] * len(temp)
        for i in range(len(self.nums)):
            r = random.randint(0, len(temp) - 1)
            result[i] = temp[r]
            temp.pop(r)
        return result


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution(nums)
    print(solution.shuffle())
