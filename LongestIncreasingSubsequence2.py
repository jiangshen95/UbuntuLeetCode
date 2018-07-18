class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = [0] * len(nums)
        size = 0
        for num in nums:
            i, j = 0, size
            while i < j:
                m = (i + j) // 2
                if dp[m] < num:
                    i = m + 1
                else:
                    j = m
            dp[i] = num
            if i == size:
                size += 1
        return size


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.lengthOfLIS(nums))