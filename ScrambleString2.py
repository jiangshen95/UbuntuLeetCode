class Solution:
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1)!=len(s2):
            return False
        if s1==s2:
            return True
        
        l = len(s1)
        dp = [[[False for i in range(l+1)] for i in range(l)] for i in range(l)]
        
        for i in range(l):
            for j in range(l):
                dp[i][j][1] = (s1[i]==s2[j])
        
        for le in range(2, l+1):
            for i in range(l-le+1):
                for j in range(l-le+1):
                    for k in range(1, le):
                        dp[i][j][le] = dp[i][j][le] or (dp[i][j][k] and dp[i+k][j+k][le-k]) or (dp[i][j+le-k][k] and dp[i+k][j][le-k])
        
        return dp[0][0][l]
        
        
        
if __name__=='__main__':
    s1 = raw_input()
    s2 = raw_input()
    solution = Solution()
    print(solution.isScramble(s1, s2))
