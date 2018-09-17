class Solution:
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0, 1]
        for i in range(2, n + 1):
            m = 0
            for j in range(1, i):
                m = max(m, max(dp[j], j) * (i - j))
            dp.append(m)
        return dp[-1]


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.integerBreak(n))
