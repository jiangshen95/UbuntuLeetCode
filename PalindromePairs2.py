class Solution:
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        m = {}
        lens = []
        for i, word in enumerate(words):
            m[word] = i
            lens.append(len(word))
        lens = list(set(lens))
        lens.sort()
        result = []
        for i, word in enumerate(words):
            j = 0
            while j < len(lens) and lens[j] <= len(word):
                pre = word[: lens[j]]
                pos = word[len(word) - lens[j]:]
                if pre[::-1] in m and i != m[pre[::-1]] and word[lens[j]:][::-1] == word[lens[j]:]:
                    result.append([i, m[pre[::-1]]])
                if lens[j] < len(word) and pos[::-1] in m and \
                        word[0: len(word) - lens[j]] == word[0: len(word) - lens[j]][::-1]:
                    result.append([m[pos[::-1]], i])
                j += 1
        return result


if __name__ == '__main__':
    words = [word for word in input().split()]
    solution = Solution()
    print(solution.palindromePairs(words))
