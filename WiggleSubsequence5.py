class Solution:
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums)
        diff = nums[1] - nums[0]
        count = 1 if diff == 0 else 2
        prediff = diff
        for i in range(2, len(nums)):
            diff = nums[i] - nums[i - 1]
            if (prediff <= 0 and diff > 0) or (prediff >= 0 and diff < 0):
                count += 1
                prediff = diff
        return count


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.wiggleMaxLength(nums))
