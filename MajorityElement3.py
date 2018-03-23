class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        cadidate = None
        
        for num in nums:
            if count == 0:
                candidate = num
            count += 1 if num == candidate else -1
        return candidate
                
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.majorityElement(nums))
