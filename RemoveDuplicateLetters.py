class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        m = {}
        for ch in s:
            if ch in m:
                m[ch] += 1
            else:
                m[ch] = 1
        pos = 0
        for i in range(len(s)):
            m[s[i]] -= 1
            if s[i] < s[pos]:
                pos = i
            if m[s[i]] == 0:
                break
        return '' if len(s) == 0 else s[pos] + self.removeDuplicateLetters(s[pos + 1:].replace(s[pos], ''))


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.removeDuplicateLetters(s))
