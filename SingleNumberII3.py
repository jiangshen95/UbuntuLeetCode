class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ones = 0
        twos = 0
        for num in nums:
            ones = (ones^num) & ~twos
            twos = (twos^num) & ~ones
        return ones
        
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.singleNumber(nums))

