class Solution:
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if not s:
            return 0
        count = [0] * 91
        maxCount = 0
        l = 0
        for r in range(len(s)):
            count[ord(s[r])] += 1
            maxCount = max(maxCount, count[ord(s[r])])
            if r - l + 1 - maxCount > k:
                count[ord(s[l])] -= 1
                l += 1
        return r - l + 1


if __name__ == '__main__':
    s = input()
    k = int(input())
    solution = Solution()
    print(solution.characterReplacement(s, k))
