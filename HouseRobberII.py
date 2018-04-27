class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def rob(begin, end):
            pre = 0
            cur = 0
            for i in range(begin, end):
                temp = cur
                cur = max(pre + nums[i], cur)
                pre = temp
            return cur
        if len(nums) == 1:
            return nums[0]
        return max(rob(0, len(nums) - 1), rob(1, len(nums)))
        
if __name__ == '__main__':
    nums = list(input())
    solution = Solution()
    print(solution.rob(nums))
