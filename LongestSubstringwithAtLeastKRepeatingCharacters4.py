class Solution:
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        def longestSubstring(start, end):
            m = {}
            for i in range(start, end):
                if s[i] not in m:
                    m[s[i]] = 1
                else:
                    m[s[i]] += 1
            i = start
            res = 0
            while i < end:
                while i < end and m[s[i]] < k:
                    i += 1
                if i == end:
                    break
                r = i
                while r < end and m[s[r]] >= k:
                    r += 1
                if r == end and i == start:
                    return end - start
                res = max(res, longestSubstring(i, r))
                i += 1
            return res
        return longestSubstring(0, len(s))


if __name__ == '__main__':
    s = input()
    k = int(input())
    solution = Solution()
    print(solution.longestSubstring(s, k))
