class Solution:
    def findMaxForm(self, strs, m: int, n: int) -> int:
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for s in strs:
            zeroes, ones = s.count('0'), s.count('1')
            for i in range(m, zeroes - 1, -1):
                for j in range(n, ones - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - zeroes][j - ones] + 1)
        return dp[m][n]


if __name__ == '__main__':
    n = int(input())
    strs = []
    for i in range(n):
        strs.append(input())
    m = int(input())
    n = int(input())

    solution = Solution()
    print(solution.findMaxForm(strs, m, n))
