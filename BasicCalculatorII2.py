class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        cur = 0
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
                    cur += num
                elif sign == '-':
                    cur -= num
                elif sign == '*':
                    cur *= num
                elif sign == '/':
                    if cur > 0:
                        cur = cur // num
                    else:
                        cur = -((-cur) // num)
            elif s[i] != ' ':
                if s[i] == '+' or s[i] == '-':
                    result += cur
                    cur = 0
                sign = s[i]
            i += 1
        return result + cur
        
if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.calculate(s))
