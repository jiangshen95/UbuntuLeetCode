class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s[::-1]


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.reverseString(s))
