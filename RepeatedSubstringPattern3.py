class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        i, j = 1, 0
        n = len(s)
        dp = [0] * (n + 1)
        while i < n:
            if s[i] == s[j]:
                i += 1
                j += 1
                dp[i] = j
            elif j == 0:
                i += 1
            else:
                j = dp[j]
        return dp[-1] != 0 and (dp[-1] % (n - dp[-1]) == 0)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.repeatedSubstringPattern(s))
