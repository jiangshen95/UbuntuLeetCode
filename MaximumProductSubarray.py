class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 0
        result = nums[0]
        dp_min = nums[0]
        dp_max = nums[0]
        for i in range(1, len(nums)):
            if nums[i]<0:
                dp_max, dp_min = dp_min, dp_max
            dp_max = max(dp_max*nums[i], nums[i])
            dp_min = min(dp_min*nums[i], nums[i])
            result = max(result, dp_max)
        return result
        
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.maxProduct(nums))
