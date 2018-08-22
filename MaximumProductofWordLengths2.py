class Solution:
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        value = {}
        maxpro = 0
        for word in words:
            v = 0
            for ch in word:
                v |= 1 << (ord(ch) - 97)
            for va, l in value.items():
                if not (v & va):
                    maxpro = max(maxpro, l * len(word))
            if v in value:
                value[v] = max(value[v], len(word))
            else:
                value[v] = len(word)
        return maxpro


if __name__ == '__main__':
    words = [word for word in input().split()]
    solution = Solution()
    print(solution.maxProduct(words))
