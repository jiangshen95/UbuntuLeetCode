class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        sign = 1
        stack = []
        i = 0
        while i < len(s):
            c = s[i]
            if c.isdigit():
                j = i
                while j < len(s) and s[j].isdigit():
                    j += 1
                num = int(s[i : j])
                i = j - 1
                result += num * sign
            elif c == '+':
                sign = 1
            elif c == '-':
                sign = -1
            elif c == '(':
                stack.append(result)
                stack.append(sign)
                sign = 1
                result = 0
            elif c == ')':
                result = result * stack[-1]
                stack.pop()
                result += stack[-1]
                stack.pop()
            print(stack)
            print(result)
            i += 1
        return result

if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.calculate(s))
