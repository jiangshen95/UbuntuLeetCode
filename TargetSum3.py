class Solution:
    def findTargetSumWays(self, nums: list, S: int) -> int:
        s = sum(nums)
        if s < S:
            return 0
        dp = [0] * (2 * s + 1)
        dp[s] = 1
        for num in nums:
            t = [0] * (2 * s + 1)
            for i in range(num, 2 * s + 1 - num):
                t[i - num] += dp[i]
                t[i + num] += dp[i]
            dp = t
        return dp[S + s]


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    S = int(input())
    solution = Solution()
    print(solution.findTargetSumWays(nums, S))
