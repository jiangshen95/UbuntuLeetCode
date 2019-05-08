class Solution:
    def findWords(self, words: list) -> list:
        dict = {}
        for i, row in enumerate(['qwertyuiop', 'asdfghjkl', 'zxcvbnm']):
            for ch in row:
                dict[ch] = 1 << i

        result = []
        for word in words:
            r = 7
            for ch in word:
                r &= dict[ch.lower()]
                if r == 0:
                    break
            if r != 0:
                result.append(word)
        return result


if __name__ == '__main__':
    n = int(input())
    words = []
    for i in range(n):
        words.append(input())

    solution = Solution()
    print(solution.findWords(words))
