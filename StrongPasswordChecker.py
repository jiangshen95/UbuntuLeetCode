class Solution:
    def strongPasswordChecker(self, s):
        """
        :type s: str
        :rtype: int
        """
        needLower, needUpper, needDigit = 1, 1, 1
        lenCounts = []
        count = 1
        for i in range(len(s)):
            if 'a' <= s[i] <= 'z':
                needLower = 0
            elif 'A' <= s[i] <= 'Z':
                needUpper = 0
            elif '0' <= s[i] <= '9':
                needDigit = 0
            if i > 0 and s[i] == s[i - 1]:
                count += 1
            else:
                if count >= 3:
                    lenCounts.append(count)
                count = 1
        if count >= 3:
            lenCounts.append(count)

        if len(s) < 6:
            return max(6 - len(s), needLower + needUpper + needDigit)
        else:
            over = max(0, len(s) - 20)
            step = over

            for i in range(len(lenCounts)):
                if over > 0 and lenCounts[i] % 3 != 2:
                    t = lenCounts[i] % 3 + 1
                    if over - t >= 0:
                        over -= t
                        lenCounts[i] -= t
            left = 0
            for i in range(len(lenCounts)):
                if over > 0 and lenCounts[i] >= 3:
                    t = lenCounts[i] - 2
                    lenCounts[i] -= over
                    over -= t
                if lenCounts[i] >= 3:
                    left += lenCounts[i] // 3
            return step + max(left, needLower + needUpper + needDigit)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.strongPasswordChecker(s))
