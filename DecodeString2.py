class Solution:
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        def decodeString(s, i):
            res = ''
            while i < len(s) and s[i] != ']':
                if not s[i].isdigit():
                    res += s[i]
                    i += 1
                else:
                    pre = i
                    while i < len(s) and s[i].isdigit():
                        i += 1
                    n = int(s[pre: i])
                    i += 1
                    temp, i = decodeString(s, i)
                    i += 1
                    for j in range(n):
                        res += temp
            return res, i
        return decodeString(s, 0)[0]


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.decodeString(s))
