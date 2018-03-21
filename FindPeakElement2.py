class Solution:
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def findPeakElement(nums, left, right):
            if left == right:
                return left
            mid = (left+right)//2
            if nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]:
                return mid
            if nums[mid]<nums[mid+1]:
                return findPeakElement(nums, mid+1, right)
            else:
                return findPeakElement(nums, left, mid)
        return findPeakElement(nums, 0, len(nums)-1)
        
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.findPeakElement(nums))
