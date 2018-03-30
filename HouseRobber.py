class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        pre, cur = 0, 0
        for num in nums:
            pre, cur = cur, max(cur, pre + num)
        return cur
        
if __name__ == '__main__':
    nums = list(input())
    solution = Solution()
    print(solution.rob(nums))
