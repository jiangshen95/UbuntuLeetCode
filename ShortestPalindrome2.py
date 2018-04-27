class Solution:
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        r = s[::-1]
        for i in range(len(s), -1, -1):
            if s[:i] == r[len(s) - i:]:
                print(i)
                return r[ : len(s) - i] + s
        
if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.shortestPalindrome(s))

