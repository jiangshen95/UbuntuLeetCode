class Solution:
    def strongPasswordChecker(self, s):
        """
        :type s: str
        :rtype: int
        """
        needLower, needUpper, needDigit = 1, 1, 1
        addTarget = max(0, 6 - len(s))
        deleteTarget = max(0, len(s) - 20)
        toAdd, toReplace = 0, 0

        j = 0
        for i in range(len(s)):
            if 'a' <= s[i] <= 'z':
                needLower = 0
            elif 'A' <= s[i] <= 'Z':
                needUpper = 0
            elif '0' <= s[i] <= '9':
                needDigit = 0
            if i - j == 2:
                if s[j] == s[j + 1] and s[j + 1] == s[i]:
                    if toAdd < addTarget:
                        toAdd += 1
                        j = i
                    else:
                        toReplace += 1
                        j = i + 1
                else:
                    j += 1
        if len(s) <= 20:
            return max(addTarget + toReplace, needLower + needUpper + needDigit)

        lenCounts = [{} for _ in range(3)]
        j = 0
        for i in range(len(s) + 1):
            if i == len(s) or s[i] != s[j]:
                l = i - j
                if l >= 3:
                    if l not in lenCounts[l % 3]:
                        lenCounts[l % 3][l] = 1
                    else:
                        lenCounts[l % 3][l] += 1
                j = i

        toReplace = 0
        toDelete = 0
        for i in range(3):
            for lentgh, count in lenCounts[i].items():
                if i < 2:
                    numLetters = i + 1
                    dec = min(count, (deleteTarget - toDelete) // numLetters)
                    toDelete += dec * numLetters
                    lenCounts[i][lentgh] -= dec

                    if lentgh - numLetters > 2:
                        if lentgh - numLetters not in lenCounts[2]:
                            lenCounts[2][lentgh - numLetters] = dec
                        else:
                            lenCounts[2][lentgh - numLetters] += dec
                toReplace += lenCounts[i][lentgh] * (lentgh // 3)

        dec = (deleteTarget - toDelete) // 3
        toReplace -= dec
        toDelete -= dec * 3
        return deleteTarget + max(toReplace, needLower + needUpper + needDigit)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.strongPasswordChecker(s))
