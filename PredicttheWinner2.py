class Solution:
    def PredictTheWinner(self, nums: list) -> bool:
        n = len(nums)
        dp = [0] * n
        for i in range(n - 1, -1, -1):
            curSum = 0
            for j in range(i, n, 1):
                curSum += nums[j]
                if i == j:
                    dp[j] = nums[i]
                else:
                    dp[j] = max(nums[i] + curSum - dp[j], nums[j] + curSum - dp[j - 1])
        return dp[n - 1] * 2 >= curSum


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.PredictTheWinner(nums))
