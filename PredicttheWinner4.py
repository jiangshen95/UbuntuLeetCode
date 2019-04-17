class Solution:
    def PredictTheWinner(self, nums: list) -> bool:
        def canWin(start, end):
            if not dp[start][end]:
                if start == end:
                    dp[start][end] = nums[start]
                else:
                    dp[start][end] = max(nums[start] - canWin(start + 1, end), nums[end] - canWin(start, end - 1))
            return dp[start][end]

        n = len(nums)
        dp = [[None] * n for _ in range(n)]
        return canWin(0, n - 1) >= 0


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    solution = Solution()
    print(solution.PredictTheWinner(nums))
