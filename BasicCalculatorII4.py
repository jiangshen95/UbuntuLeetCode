class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        pre = 0
        result = 0
        sign = '+'
        while i < len(s):
            if s[i].isdigit():
                j = i + 1
                while j < len(s) and s[j].isdigit():
                    j += 1
                num = int(s[i : j])
                i = j - 1
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
                        pre = pre // num
                    else:
                        pre = -((-pre) // num)
            elif s[i] != ' ':
                sign = s[i]
            i += 1
        return result + pre
        
if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.calculate(s))
