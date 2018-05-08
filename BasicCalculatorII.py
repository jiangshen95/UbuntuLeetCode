class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        
        i = 0
        sign = '+'
        while i < len(s):
            if s[i].isdigit():
                j = i + 1
                while j < len(s) and s[j].isdigit():
                    j += 1
                num = int(s[i : j])
                i = j - 1
                if sign == '+':
                    stack.append(num)
                elif sign == '-':
                    stack.append(-num)
                elif sign == '*':
                    stack[-1] = stack[-1] * num
                elif sign == '/':
                    if stack[-1] > 0:
                        stack[-1] = stack[-1] // num
                    else:
                        stack[-1] = -((-stack[-1]) // num)
            elif s[i] != ' ':
                sign = s[i]
            print(stack)
            i += 1
        return sum(stack)
        
if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.calculate(s))
