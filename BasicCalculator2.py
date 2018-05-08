class Solution:
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        signs = [1, 1]
        i = 0
        while i < len(s):
            c = s[i]
            if c.isdigit():
                j = i
                while j < len(s) and s[j].isdigit():
                    j += 1
                num = int(s[i : j])
                i = j - 1
                result += num * signs[-1]
                signs.pop()
            elif c == ')':
                signs.pop()
            elif c != ' ':
                signs.append(signs[-1] * (-1 if c == '-' else 1))
            i += 1
        return result

if __name__ == '__main__':
    s = raw_input()
    solution = Solution()
    print(solution.calculate(s))
