class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        lastNoneZeroFoundAt = 0
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[lastNoneZeroFoundAt], nums[i] = nums[i], nums[lastNoneZeroFoundAt]
                lastNoneZeroFoundAt += 1


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    solution.moveZeroes(nums)
    print(nums)
