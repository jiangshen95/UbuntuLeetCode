class Solution:
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0]

        for i in range(1, n + 1):
            val, j = i, 1
            while j * j <= i:
                val = min(val, dp[i - j * j] + 1)
                j += 1
            dp.append(val)
        return dp[n]

if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.numSquares(n))
