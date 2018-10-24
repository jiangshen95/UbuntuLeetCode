class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = {}
        for ch in s:
            if ch not in m:
                m[ch] = 0
            m[ch] += 1
        for i in range(len(s)):
            if m[s[i]] == 1:
                return i
        return -1


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.firstUniqChar(s))
