class Solution:
    def findAllConcatenatedWordsInADict(self, words):
        if len(words) <= 2:
            return []
        dict = set(words)
        result = []
        for word in words:
            dict.remove(word)
            if not word:
                continue
            n = len(word)
            dp = [False] * (n + 1)
            dp[0] = True
            for i in range(1, n + 1):
                for j in range(0, i):
                    if dp[j] and word[j: i] in dict:
                        dp[i] = True
                        break
            if dp[-1]:
                result.append(word)
            dict.add(word)
        return result


if __name__ == '__main__':
    n = int(input())
    words = []
    for i in range(n):
        words.append(input())
    solution = Solution()
    print(solution.findAllConcatenatedWordsInADict(words))
