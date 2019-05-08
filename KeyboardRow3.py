class Solution:
    def findWords(self, words: list) -> list:
        return [word for row in [set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')] for word in words if set(word.lower()) <= row]


if __name__ == '__main__':
    n = int(input())
    words = []
    for i in range(n):
        words.append(input())

    solution = Solution()
    print(solution.findWords(words))
