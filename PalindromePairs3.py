class Solution:
    class TireNode:
        def __init__(self):
            self.next = {}
            self.index = -1
            self.list = []

    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        def addWord(root, word, index):
            for i in range(len(word) - 1, -1, -1):
                if word[i] not in root.next:
                    root.next[word[i]] = self.TireNode()
                if word[0: i + 1] == word[0: i + 1][::-1]:
                    root.list.append(index)
                root = root.next[word[i]]
            root.list.append(index)
            root.index = index

        def search(root, i):
            for j in range(len(words[i])):
                if root.index >= 0 and root.index != i and words[i][j:] == words[i][j:][::-1]:
                    result.append([i, root.index])
                if words[i][j] in root.next:
                    root = root.next[words[i][j]]
                else:
                    return
            for j in root.list:
                if i == j:
                    continue
                result.append([i, j])

        result = []
        root = self.TireNode()
        for i, word in enumerate(words):
            addWord(root, word, i)
        for i in range(len(words)):
            search(root, i)
        return result


if __name__ == '__main__':
    words = [word for word in input().split()]
    solution = Solution()
    print(solution.palindromePairs(words))
