class Solution:
    def PredictTheWinner(self, nums: list) -> bool:
        n = len(nums)
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            curSum = 0
            for j in range(i, n, 1):
                curSum += nums[j]
                if i == j:
                    dp[i][j] = nums[i]
                else:
                    dp[i][j] = max(nums[i] + curSum - dp[i + 1][j], nums[j] + curSum - dp[i][j - 1])
        return dp[0][n - 1] * 2 >= curSum


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.PredictTheWinner(nums))
