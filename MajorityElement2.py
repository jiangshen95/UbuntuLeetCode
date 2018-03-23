class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        return nums[len(nums)//2]
                
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.majorityElement(nums))
