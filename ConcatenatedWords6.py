class Solution:
    def findAllConcatenatedWordsInADict(self, words):
        def canConcated(word, dict):
            n = len(word)
            stack = [0]
            seed = {0}
            while stack:
                node = stack.pop()
                if node == n:
                    return True
                for i in range(1, n - node + 1, 1):
                    if word[node: node + i] in dict and node + i not in seed:
                        stack.append(node + i)
                        seed.add(node + i)
            return False

        if len(words) <= 2:
            return []
        dict = set()
        result = []
        words.sort(key=lambda x: len(x))
        for word in words:
            if not word:
                continue
            if canConcated(word, dict):
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
