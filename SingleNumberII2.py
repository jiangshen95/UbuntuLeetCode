class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hash_table = {}
        for num in nums:
            if num not in hash_table:
                hash_table[num] = 0
            hash_table[num] += 1
            if hash_table[num] == 3:
                hash_table.pop(num)
        return hash_table.keys()[0]
        
if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.singleNumber(nums))

