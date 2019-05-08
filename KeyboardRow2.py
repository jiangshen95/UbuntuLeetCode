class Solution:
    def findWords(self, words: list) -> list:
        row1, row2, row3 = set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')
        result = []
        for word in words:
            w = set(word.lower())
            if w <= row1 or w <= row2 or w <= row3:
                result.append(word)
        return result


if __name__ == '__main__':
    n = int(input())
    words = []
    for i in range(n):
        words.append(input())

    solution = Solution()
    print(solution.findWords(words))
