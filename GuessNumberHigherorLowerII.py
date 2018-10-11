class Solution:
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        for i in range(2, n + 1):
            for j in range(i - 1, 0, -1):
                dp[j][i] = min(k + max(dp[j][k - 1], dp[k + 1][i]) for k in range(j, i))
        return dp[1][n]


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.getMoneyAmount(n))
