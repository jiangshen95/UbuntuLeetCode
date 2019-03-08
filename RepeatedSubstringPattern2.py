class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        for i in range(1, n // 2 + 1):
            if n % i == 0:
                t = s[: i]
                if t * (n // i) == s:
                    return True
        return False


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.repeatedSubstringPattern(s))
