class Solution:
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums)
        i = 0
        dele = 0
        direct = 0
        while i < len(nums):
            while i + 1 < len(nums) and nums[i + 1] == nums[i]:
                i += 1
                dele += 1
            j = i
            isright = True
            if j + 1 < len(nums) and nums[j + 1] > nums[j]:
                if direct == -1:
                    isright = False
                direct = 1
                while j + 1 < len(nums) and nums[j + 1] >= nums[j]:
                    j += 1
            elif j + 1 < len(nums) and nums[j + 1] < nums[j]:
                if direct == 1:
                    isright = False
                direct = -1
                while j + 1 < len(nums) and nums[j + 1] <= nums[j]:
                    j += 1
            if j > i:
                dele += j - i - 1 if isright else j - i
            i = j + 1

        return len(nums) - dele


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.wiggleMaxLength(nums))
