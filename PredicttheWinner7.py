class Solution:
    def PredictTheWinner(self, nums: list) -> bool:
        def getScore(start, end):
            if start > end:
                return 0
            if not dp[start][end]:
                a = nums[start] + min(getScore(start + 1, end - 1), getScore(start + 2, end))
                b = nums[end] + min(getScore(start + 1, end - 1), getScore(start, end - 2))
                dp[start][end] = max(a, b)
            return dp[start][end]

        n = len(nums)
        dp = [[None] * n for _ in range(n)]
        return getScore(0, n - 1) * 2 >= sum(nums)


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.PredictTheWinner(nums))
