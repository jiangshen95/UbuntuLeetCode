class Solution:
    def findAllConcatenatedWordsInADict(self, words):
        if len(words) <= 2:
            return []
        dict = set(words)
        result = []
        for word in words:
            if not word:
                continue
            n = len(word)
            dp = [False] * (n + 1)
            dp[0] = True
            for i in range(0, n):
                if not dp[i]:
                    continue
                for j in range(i + 1, n + 1, 1):
                    if j - i < n and word[i: j] in dict:
                        dp[j] = True
                if dp[-1]:
                    result.append(word)
                    break
        return result


if __name__ == '__main__':
    n = int(input())
    words = []
    for i in range(n):
        words.append(input())
    solution = Solution()
    print(solution.findAllConcatenatedWordsInADict(words))
