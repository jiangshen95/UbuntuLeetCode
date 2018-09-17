class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        l = 0
        r = len(s) - 1
        s = list(s)
        while l < r:
            s[l], s[r] = s[r], s[l]
            l += 1
            r -= 1
        s = ''.join(s)
        return s


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.reverseString(s))
