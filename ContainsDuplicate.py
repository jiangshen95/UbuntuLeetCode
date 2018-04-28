class Solution:
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return len(nums) > len(set(nums))
        
if __name__ == '__main__':
    nums = list(input())
    solution = Solution()
    print(solution.containsDuplicate(nums))
