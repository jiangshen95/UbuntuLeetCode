class Solution:
    def PredictTheWinner(self, nums: list) -> bool:
        n = len(nums)
        dp = [[0] * n for _ in range(n)]
        for l in range(n):
            for i in range(n - l):
                j = i + l
                if i == j:
                    dp[i][j] = nums[i]
                else:
                    dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
        return dp[0][n - 1] >= 0


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.PredictTheWinner(nums))
