class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hash_table = {}
        for num in nums:
            if num in hash_table:
                hash_table.pop(num)
            else:
                hash_table[num] = 1
        return hash_table.keys()[0]
        
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.singleNumber(nums))
