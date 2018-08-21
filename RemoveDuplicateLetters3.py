class Solution:
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ''
        m = {v: i for i, v in enumerate(s)}
        result = ''
        begin = 0
        end = min(m.values())
        while m:
            minChar = min(s[begin: end + 1])
            result += minChar
            for i in range(begin, end + 1):
                if s[i] == minChar:
                    begin = i + 1
                    break
            del m[minChar]
            if not m:
                break
            if s[end] == minChar:
                end = min(m.values())
            s = s.replace(minChar, '|')

        return result


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.removeDuplicateLetters(s))
