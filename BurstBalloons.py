class Solution:
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        dp = [[0 for _ in range(n + 2)] for _ in range(n + 2)]
        nums = [1] + nums + [1]
        for i in range(n, 0, -1):
            for j in range(i, n + 1):
                for k in range(i, j + 1):
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] +
                                           nums[k] * nums[i - 1] * nums[j + 1])
        return dp[1][n]


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.maxCoins(nums))
