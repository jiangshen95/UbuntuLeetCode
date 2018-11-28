class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = [0] * 128
        use = 0
        for c in s:
            m[ord(c)] += 1
            if m[ord(c)] % 2 == 0:
                use += 2
        return use + (use < len(s))


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.longestPalindrome(s))
