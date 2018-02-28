class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        memo = {}
        def wordBreak(s):
            result = []
            if len(s) == 0:
                result.append("")
                return result
            if s in memo:
                return memo[s]
            for word in wordDict:
                if s[ : len(word)] == word:
                    #sublist = wordBreak(s[len(word) : ])
                    #result.append((word + ("" if len(sub)==0 else " ") +sub) for sub in wordBreak(s[len(word) : ]))
                    result += [(word + ("" if len(sub)==0 else " ") +sub) for sub in wordBreak(s[len(word) : ])]
            memo[s] = result
            return result
        return wordBreak(s)

if __name__=='__main__':
    s = raw_input()
    n = int(raw_input())
    wordDict = []
    for i in range(n):
        word = raw_input()
        wordDict.append(word)
    solution = Solution()
    print(solution.wordBreak(s, wordDict))
