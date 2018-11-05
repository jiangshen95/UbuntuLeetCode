class Solution:
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        num = 0
        curStr = ''
        for ch in s:
            if ch.isdigit():
                num = num * 10 + int(ch)
            elif ch == '[':
                stack.append((curStr, num))
                num = 0
                curStr = ''
            elif ch == ']':
                temp, times = stack.pop()
                for i in range(times):
                    temp += curStr
                curStr = temp
            else:
                curStr += ch
        return curStr


if __name__ == '__main__':
    s = input()
    solution = Solution()
    print(solution.decodeString(s))
