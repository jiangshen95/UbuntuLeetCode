class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return any(s[: i] * (len(s) // i) == s for i in range(1, len(s) // 2 + 1) if len(s) % i == 0)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.repeatedSubstringPattern(s))
