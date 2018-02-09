class Solution:
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        pair = [[False for i in range(len(s))] for j in range(len(s))]
        cut = [i-1 for i in range(len(s)+1)]
        
        for i in range(len(s)):
            for j in range(i+1):
                if s[i]==s[j] and (i-j<=1 or pair[j+1][i-1]):
                    pair[j][i] = True
                    cut[i+1] = min(cut[i+1], cut[j]+1)
        return cut[len(s)]
        
if __name__=='__main__':
    s = raw_input()
    solution = Solution()
    print(solution.minCut(s))
