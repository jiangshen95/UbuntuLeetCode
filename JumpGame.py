class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        lastposition=len(nums)-1
        for i in range(len(nums)-1,-1,-1):
            if i+nums[i]>=lastposition:
                lastposition=i
        return lastposition == 0
        
if __name__=='__main__':
    nums=list(input())
    solution=Solution()
    print(solution.canJump(nums))
