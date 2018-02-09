class Solution:
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        cut = [i-1 for i in range(len(s)+1)]
        
        for i in range(len(s)):
            j = 0
            while i-j>=0 and i+j<len(s) and s[i-j]==s[i+j]:
                cut[i+j+1] = min(cut[i+j+1], cut[i-j]+1)
                j += 1
            j = 0
            while i-j+1>=0 and i-j+1<len(s) and i+j<len(s) and s[i-j+1]==s[i+j]:
                cut[i+j+1] = min(cut[i+j+1], cut[i-j+1]+1)
                j += 1
            
        return cut[len(s)]
        
if __name__=='__main__':
    s = raw_input()
    solution = Solution()
    print(solution.minCut(s))
