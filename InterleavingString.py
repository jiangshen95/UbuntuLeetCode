class Solution:
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        if len(s1)+len(s2)!=len(s3):
            return False
        dp = [False]*(len(s2)+1)
        dp[0] = True
        for i in range(len(s1)+1):
            for j in range(len(s2)+1):
                if i==0 and j==0:
                    continue
                if (j>0 and dp[j-1] and s2[j-1]==s3[i+j-1]) or (i>0 and dp[j] and s1[i-1]==s3[i+j-1]):
                    dp[j] = True
                else:
                    dp[j] = False
                
        return dp[len(s2)]
        
if __name__=='__main__':
    s1 = raw_input()
    s2 = raw_input()
    s3 = raw_input()
    
    solution = Solution()
    print(solution.isInterleave(s1, s2, s3))
