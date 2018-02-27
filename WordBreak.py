class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        dp = [False]*len(s)
        
        for i in range(len(s)):
            for w in wordDict:
                if w == s[i-len(w)+1 : i+1] and (dp[i-len(w)] or i-len(w)==-1):
                    dp[i] = True
        return dp[-1]
        
if __name__=='__main__':
    s = raw_input()
    n = int(raw_input())
    wordDict = []
    for i in range(n):
        word = raw_input()
        wordDict.append(word)
    solution = Solution()
    print(solution.wordBreak(s, wordDict))
