class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        pre = 0
        num = 0
        result = 0
        sign = '+'
        s = '+' + s + '+'
        while i < len(s):
            if s[i].isdigit():
                num = num * 10 + int(s[i])
            elif s[i] != ' ':
                if sign == '+':
                    result += pre
                    pre = num
                elif sign == '-':
                    result += pre
                    pre = -num
                elif sign == '*':
                    pre *= num
                elif sign == '/':
                    if pre > 0:
                        pre //= num
                    else:
                        pre = -((-pre)//num)
                num = 0
                sign = s[i]
            i += 1
        return result + pre
        
if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.calculate(s))
