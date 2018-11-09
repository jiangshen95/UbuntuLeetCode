class Solution:
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        i = 0
        res = 0
        while i + k <= len(s):
            if i > 0 and s[i] == s[i - 1]:
                i += 1
                continue
            m = {}
            mask = 0
            max_index = i
            for j in range(i, len(s)):
                if s[j] not in m:
                    m[s[j]] = 0
                m[s[j]] += 1
                t = ord(s[j]) - ord('a')
                if m[s[j]] < k:
                    mask |= 1 << t
                else:
                    mask &= ~(1 << t)
                if mask == 0:
                    max_index = j
                    res = max(res, j - i + 1)
            i = max_index + 1
        return res


if __name__ == '__main__':
    s = input()
    k = int(input())
    solution = Solution()
    print(solution.longestSubstring(s, k))
