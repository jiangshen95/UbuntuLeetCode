class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        lastNoneZeroFoundAt = 0
        for num in nums:
            if num != 0:
                nums[lastNoneZeroFoundAt] = num
                lastNoneZeroFoundAt += 1
        while lastNoneZeroFoundAt < len(nums):
            nums[lastNoneZeroFoundAt] = 0
            lastNoneZeroFoundAt += 1

if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    solution.moveZeroes(nums)
    print(nums)
