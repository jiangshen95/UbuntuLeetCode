class Solution:
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num_set = set(nums)
        result = 0
        for num in nums:
            if (num-1 not in num_set) and (num in num_set):
                curr = num+1
                while curr in num_set:
                    curr += 1
                result = max(result, curr-num)
        return result

if __name__=='__main__':
    nums = list(input())
    solution = Solution()
    print(solution.longestConsecutive(nums))
