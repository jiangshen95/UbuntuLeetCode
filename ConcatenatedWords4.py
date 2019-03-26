class Solution:
    def findAllConcatenatedWordsInADict(self, words):
        def canConcated(word, pos, dict, count):
            if pos >= len(word) and count >= 2:
                return True
            for i in range(pos, len(word)):
                if word[pos: i + 1] in dict and canConcated(word, i + 1, dict, count + 1):
                    return True
            return False

        if len(words) <= 2:
            return []
        dict = set()
        result = []
        words.sort(key=lambda x: len(x))
        for word in words:
            if not word:
                continue
            if canConcated(word, 0, dict, 0):
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
