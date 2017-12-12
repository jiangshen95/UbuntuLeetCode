class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        curr = 0
        for num in nums:
            if curr<2 or num>nums[curr-2]:
                nums[curr]=num
                curr += 1
        return curr
        
if __name__=="__main__":
    nums = list(input())
    solution=Solution()
    print(solution.removeDuplicates(nums))
