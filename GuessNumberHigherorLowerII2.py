class Solution:
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        def help(start, end):
            if start >= end:
                return 0
            if dp[start][end] > 0:
                return dp[start][end]
            dp[start][end] = min(k + max(help(start, k - 1), help(k + 1, end)) for k in range(start, end))
            return dp[start][end]
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        return help(1, n)


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.getMoneyAmount(n))
