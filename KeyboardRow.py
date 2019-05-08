class Solution:
    def findWords(self, words: list) -> list:
        import re
        return list(filter(re.compile(r'(?i)([qwertyuiop]*|[asdfghjkl]*|[zxcvbnm]*)$').match, words))


if __name__ == '__main__':
    n = int(input())
    words = []
    for i in range(n):
        words.append(input())

    solution = Solution()
    print(solution.findWords(words))
