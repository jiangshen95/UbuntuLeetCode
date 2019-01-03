class Solution:
    def strongPasswordChecker(self, s):
        """
        :type s: str
        :rtype: int
        """
        needLower, needUpper, needDigit = 1, 1, 1
        count = 1
        change = 0
        one, two = 0, 0
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
                    change += count // 3
                    if count % 3 == 0:
                        one += 1
                    elif count % 3 == 1:
                        two += 1
                count = 1
        if count >= 3:
            change += count // 3
            if count % 3 == 0:
                one += 1
            elif count % 3 == 1:
                two += 1

        if len(s) < 6:
            return max(6 - len(s), needLower + needUpper + needDigit)
        elif len(s) <= 20:
            return max(change, needLower + needUpper + needDigit)
        else:
            deleteTarget = len(s) - 20
            change -= min(one, deleteTarget)
            change -= min(max(0, deleteTarget - one), two * 2) // 2
            change -= max(0, deleteTarget - one - two * 2) // 3

            return deleteTarget + max(change, needDigit + needUpper + needLower)


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.strongPasswordChecker(s))
