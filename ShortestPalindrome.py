class Solution:
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        i = 0
        for j in range(len(s) - 1, -1, -1):
            if s[i] == s[j]:
                i += 1
        if i == len(s):
            return s
        return s[i:][::-1] + self.shortestPalindrome(s[ : i]) + s[i : ]
        
if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.shortestPalindrome(s))
