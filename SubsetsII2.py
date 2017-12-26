class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = [[]]
        nums.sort()
        
        i = 0
        while i<len(nums):
            count = 0
            while i+count<len(nums) and nums[i+count]==nums[i]:
                count += 1
            size = len(result)
            for j in range(size):
                temp = [x for x in result[j]]
                for k in range(count):
                    temp.append(nums[i])
                    result += [[x for x in temp]]
            i += count
        
        return result
        
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    result = solution.subsetsWithDup(nums)
    print(result)
