class Solution:
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = len(nums)-1
        while left<right:
            mid = (left+right)//2
            if nums[mid]<nums[mid+1]:
                left = mid+1
            else:
                right = mid
        return left
        
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.findPeakElement(nums))
