class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        import re
        return re.match(r'^([a-z]+)\1+$', s) != None


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.repeatedSubstringPattern(s))
