class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def getSubsets(end, nums, one, result):
            a = one
            result.append(a)
            for i in range(end, len(nums)):
                getSubsets(i+1, nums, one+[nums[i]], result)
        one = []
        result = []
        getSubsets(0, nums, one, result)
        return result
        
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.subsets(nums))
