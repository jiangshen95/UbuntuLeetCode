class Solution:
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        def computeCommenLength(t):
            next = [0] * len(t)
            for i in range(1, len(t)):
                k = next[i - 1]
                while k > 0 and t[i] != t[k]:
                    k = next[k -1]
                if t[i] == t[k]:
                    next[i] = k + 1
            return next[-1]
        palindLen = computeCommenLength(s + "#" + s[::-1])
        return s[palindLen : ][::-1] + s
        
if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.shortestPalindrome(s))
