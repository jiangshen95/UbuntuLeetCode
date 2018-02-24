class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        for num in nums:
            a ^= num
        return a
        
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.singleNumber(nums))
