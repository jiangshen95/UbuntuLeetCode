class Solution:
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        def computeCommenLength(t):
            next = [0] * len(t)
            k = 0
            i = 1
            while i < len(t):
                if k == 0 and t[k] != t[i]:
                    i += 1
                elif t[k] == t[i]:
                    k += 1
                    next[i] = k
                    i += 1
                else:
                    k = next[k - 1]
            return next[-1]
        palindLen = computeCommenLength(s + "#" + s[::-1])
        return s[palindLen : ][::-1] + s
        
if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.shortestPalindrome(s))

