class Solution:
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        ls = len(s)
        lt = len(t)
        
        dp = [[0]*(lt+1) for i in range(ls+1)]
        #print(dp)
        for i in range(ls+1):
            dp[i][0] = 1
        for i in range (1, ls+1):
            for j in range(1, lt+1):
                if s[i-1]==t[j-1]:
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        return dp[ls][lt]
        
if __name__=='__main__':
    s = raw_input()
    t = raw_input()
    solution = Solution()
    print(solution.numDistinct(s, t))
