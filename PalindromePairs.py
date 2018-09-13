class Solution:
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        m = {word: i for i, word in enumerate(words)}
        result = []
        for i, word in enumerate(words):
            for j in range(len(word) + 1):
                pre = word[: j]
                pos = word[j:]
                if pre[::-1] in m and i != m[pre[::-1]] and pos == pos[::-1]:
                    result.append([i, m[pre[::-1]]])
                if j != 0 and pos[::-1] in m and i != m[pos[::-1]] and pre == pre[::-1]:
                    result.append([m[pos[::-1]], i])
        return result


if __name__ == '__main__':
    words = [word for word in input().split()]
    solution = Solution()
    print(solution.palindromePairs(words))
