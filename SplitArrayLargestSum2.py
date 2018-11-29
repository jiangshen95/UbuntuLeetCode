class Solution:
    # Time Limit Exceeded
    def splitArray(self, nums, m):
        """
        :type nums: List[int]
        :type m: int
        :rtype: int
        """
        n = len(nums)
        INT_MAX = (1 << 31) - 1;
        dp = [[INT_MAX] * (n + 1) for _ in range(m + 1)]
        sums = [0] * (n + 1)
        for i in range(n):
            sums[i + 1] = sums[i] + nums[i]

        dp[0][0] = 0
        for i in range(1, m + 1):
            for j in range(i, n + 1):
                for k in range(i - 1, j):
                    t = max(dp[i - 1][k], sums[j] - sums[k])
                    if t <= dp[i][j]:
                        dp[i][j] = t
                    else:
                        break
                    # dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sums[j] - sums[k]))
        return dp[m][n]


if __name__ == '__main__':
    nums = [int(num) for num in input().split()]
    m = int(input())
    solution = Solution()
    print(solution.splitArray(nums, m))
