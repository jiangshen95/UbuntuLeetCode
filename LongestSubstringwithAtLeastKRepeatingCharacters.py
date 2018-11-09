class Solution:
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        res = 0
        for h in range(1, 27):
            i, j = 0, 0
            unique = 0
            noLessThenK = 0
            m = {}
            while j < len(s):
                if unique <= h:
                    if s[j] not in m:
                        m[s[j]] = 0
                        unique += 1
                    m[s[j]] += 1
                    if m[s[j]] == k:
                        noLessThenK += 1
                    j += 1
                else:
                    if m[s[i]] == k:
                        noLessThenK -= 1
                    m[s[i]] -= 1
                    if m[s[i]] == 0:
                        unique -= 1
                        m.pop(s[i])
                    i += 1
                if unique == h and noLessThenK == h:
                    res = max(res, j - i)
        return res


if __name__ == '__main__':
    s = input()
    k = int(input())
    solution = Solution()
    print(solution.longestSubstring(s, k))
