class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = [0] * 128
        odd = 0
        for c in s:
            m[ord(c)] += 1
        for n in m:
            if n % 2:
                odd += 1
        return len(s) - odd + (odd > 0)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.longestPalindrome(s))
