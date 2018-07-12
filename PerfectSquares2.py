class Solution:
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        INT_MAX = 2147483647
        dp = [INT_MAX] * (n + 1)
        dp[0] = 0

        for i in range(0, n + 1):
            j = 1
            while i + j * j <= n:
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1)
                j += 1
        return dp[n]

if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.numSquares(n))
