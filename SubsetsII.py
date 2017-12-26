class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = [[]]
        nums.sort()
        
        size = 0
        
        for i in range(len(nums)):
            begin = size if i>0 and nums[i]==nums[i-1] else 0
            size = len(result)
            for j in range(begin, size):
                temp = [x for x in result[j]]
                temp.append(nums[i])
                result.append(temp)
        return result
        
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    result = solution.subsetsWithDup(nums)
    print(result)
