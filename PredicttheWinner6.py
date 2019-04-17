class Solution:
    def PredictTheWinner(self, nums: list) -> bool:
        n = len(nums)
        dp = [0] * n
        for i in range(n - 1, -1, -1):
            for j in range(i, n, 1):
                if i == j:
                    dp[j] = nums[i]
                else:
                    dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1])
        return dp[n - 1] >= 0


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.PredictTheWinner(nums))
