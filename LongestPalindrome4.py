class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        import collections
        use = sum(v & (~1) for v in collections.Counter(s).values())
        return use + (use < len(s))


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.longestPalindrome(s))
