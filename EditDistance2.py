class Solution:
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m = len(word1)
        n = len(word2)
        dp = [i for i in range(m+1)]
        #print(dp)
        for j in range(1, n+1):
            pre = dp[0]
            dp[0] = j
            for i in range(1, m+1):
                temp = dp[i]
                if word1[i-1]==word2[j-1]:
                    dp[i] = min(min(dp[i-1]+1, dp[i]+1), pre)
                else:
                    dp[i] = min(min(dp[i-1]+1, dp[i]+1), pre+1)
                pre = temp
                
        return dp[m]
        
        
        
if __name__=='__main__':
    word1 = raw_input()
    word2 = raw_input()
    solution = Solution()
    print(solution.minDistance(word1, word2))
