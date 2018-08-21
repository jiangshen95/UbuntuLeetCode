class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = ''
        while s:
            i = min(map(s.rindex, set(s)))
            c = min(s[: i + 1])
            result += c
            s = s[s.index(c):].replace(c, '')
        return result


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.removeDuplicateLetters(s))
