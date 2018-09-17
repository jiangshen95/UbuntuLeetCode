import re

class Solution:
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = re.findall('(?i)[aeiou]', s)
        return re.sub('(?i)[aeiou]', lambda m: vowels.pop(), s)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.reverseVowels(s))
