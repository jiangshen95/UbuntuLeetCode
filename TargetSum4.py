class Solution:
    def findTargetSumWays(self, nums: list, S: int) -> int:
        s = sum(nums)
        if s < S or (s + S) % 2 == 1:
            return 0
        target = (s + S) // 2
        dp = {0: 1}
        for num in nums:
            t = {}
            for i, c in dp.items():
                t[i + num] = t.get(i + num, 0) + c
                t[i] = t.get(i, 0) + c
            dp = t
        return dp.get(target, 0)
        # dp = [0] * (target + 1)
        # dp[0] = 1
        # for num in nums:
        #     for i in range(target, num - 1, -1):
        #         dp[i] += dp[i - num]
        # return dp[target]


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    S = int(input())
    solution = Solution()
    print(solution.findTargetSumWays(nums, S))
