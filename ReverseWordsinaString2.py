import re

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        def reverse(s):
            res = ''
            for i in range(len(s)-1, -1, -1):
                res += s[i]
            return res
            
        s = reverse(s)
        
        res = ''
        
        i = 0
        storeIndex = 0
        while i<len(s):
            if s[i] == ' ':
                i += 1
                continue
            j = i
            while j<len(s) and s[j]!=' ':
                j += 1
            res += reverse(s[i:j]) + ' '
            i = j
        
        return res.rstrip()
        
if __name__=='__main__':
    s = raw_input()
    solution = Solution()
    print(solution.reverseWords(s))
