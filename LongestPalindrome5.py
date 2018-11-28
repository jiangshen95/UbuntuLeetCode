class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        import collections
        counts = collections.Counter(s).values()
        return sum(v & ~1 for v in counts) + any(v & 1 for v in counts)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.longestPalindrome(s))
