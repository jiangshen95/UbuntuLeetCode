import re

class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = (c for c in reversed(s) if c in 'aeiouAEIOU')
        return re.sub('(?i)[aeiou]', lambda m: next(vowels), s)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.reverseVowels(s))
