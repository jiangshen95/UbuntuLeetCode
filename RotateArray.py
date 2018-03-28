class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        nums[ : ] = nums[n-k : ] + nums[ : n-k]

if __name__ == '__main__':
    nums = list(input())
    k = int(raw_input())
    solution = Solution()
    solution.rotate(nums, k)
    print(nums)
