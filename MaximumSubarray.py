class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        curmax=nums[0]
        globalmax=nums[0]
        for i in range(1,len(nums)):
            curmax=curmax+nums[i] if curmax>0 else nums[i]
            globalmax=max(curmax,globalmax)
        return globalmax
        
if __name__=='__main__':
    nums=input()
    nums=list(nums)
    solution=Solution()
    print(solution.maxSubArray(nums))
