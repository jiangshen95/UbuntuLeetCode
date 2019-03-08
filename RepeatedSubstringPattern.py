class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s * 2)[1: -1]


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.repeatedSubstringPattern(s))
