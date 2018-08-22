class Solution:
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        n = len(words)
        value = [0] * n
        maxpro = 0
        for i, word in enumerate(words):
            for ch in word:
                value[i] |= 1 << (ord(ch) - 97)
            for j in range(i):
                if not (value[j] & value[i]):
                    maxpro = max(maxpro, len(words[i]) * len(words[j]))
        return maxpro


if __name__ == '__main__':
    words = [word for word in input().split()]
    solution = Solution()
    print(solution.maxProduct(words))
