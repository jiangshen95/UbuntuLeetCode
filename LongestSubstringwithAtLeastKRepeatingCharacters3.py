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
                m[c] = 1
            else:
                m[c] += 1
        for i in range(len(s)):
            if m[s[i]] < k:
                left = self.longestSubstring(s[: i], k)
                right = self.longestSubstring(s[i + 1:], k)
                return max(left, right)
        return len(s)


if __name__ == '__main__':
    s = input()
    k = int(input())
    solution = Solution()
    print(solution.longestSubstring(s, k))
