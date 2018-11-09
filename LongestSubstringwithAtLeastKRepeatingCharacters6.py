class Solution:
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        m = {}
        for c in s:
            if c not in m:
                m[c] = 0
            m[c] += 1

        ok = True
        res = 0
        pre_index = 0
        for i in range(len(s)):
            if m[s[i]] < k:
                res = max(res, self.longestSubstring(s[pre_index: i], k))
                ok = False
                pre_index = i + 1
        return len(s) if ok else max(res, self.longestSubstring(s[pre_index:], k))


if __name__ == '__main__':
    s = input()
    k = int(input())
    solution = Solution()
    print(solution.longestSubstring(s, k))
