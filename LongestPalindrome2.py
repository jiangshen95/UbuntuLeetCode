class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        import collections
        odds = sum(v & 1 for v in collections.Counter(s).values())
        return len(s) - odds + (odds > 0)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.longestPalindrome(s))
