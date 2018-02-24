class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return (int)(3*sum(set(nums))-sum(nums))/2
        
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.singleNumber(nums))
