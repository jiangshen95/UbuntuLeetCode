class Solution:
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        ls = len(s)
        lt = len(t)
        
        dp = [0]*(lt+1)
        dp[0] = 1
        
        for i in range(1, ls+1):
            for j in range(lt, 0, -1):
                if s[i-1]==t[j-1]:
                    dp[j] = dp[j-1]+dp[j]
        
        return dp[lt]
        
if __name__=='__main__':
    s = raw_input()
    t = raw_input()
    solution = Solution()
    print(solution.numDistinct(s, t))
