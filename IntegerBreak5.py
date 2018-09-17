class Solution:
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0, 1, 1, 2, 4, 6, 9]
        for i in range(7, n + 1):
            dp.append(3 * dp[i - 3])
        return dp[n]


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.integerBreak(n))
