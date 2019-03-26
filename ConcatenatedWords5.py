class Solution:
    def findAllConcatenatedWordsInADict(self, words):
        class TireNode:
            def __init__(self):
                self.children = {}
                self.isEnd = False

        def addWord(word, root):
            cur = root
            for ch in word:
                if ch not in cur.children:
                    cur.children[ch] = TireNode()
                cur = cur.children[ch]
            cur.isEnd = True

        def canConcated(word, pos, root, count):
            if pos >= len(word) and count >= 2:
                return True
            cur = root
            for i in range(pos, len(word)):
                if word[i] not in cur.children:
                    return False
                cur = cur.children[word[i]]
                if cur.isEnd and canConcated(word, i + 1, root, count + 1):
                    return True
            return False

        if len(words) <= 2:
            return []
        result = []
        root = TireNode()
        words.sort(key=lambda x: len(x))
        for word in words:
            if not word:
                continue
            if canConcated(word, 0, root, 0):
                result.append(word)
            addWord(word, root)
        return result


if __name__ == '__main__':
    n = int(input())
    words = []
    for i in range(n):
        words.append(input())
    solution = Solution()
    print(solution.findAllConcatenatedWordsInADict(words))
