class Solution:
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        result = []
        for i in range(len(input)):
            if input[i] in '+-*':
                num1 = self.diffWaysToCompute(input[:i])
                num2 = self.diffWaysToCompute(input[i + 1:])
                for m in num1:
                    for n in num2:
                        if input[i] == '+':
                            result.append(m + n)
                        elif input[i] == '-':
                            result.append(m - n)
                        elif input[i] == '*':
                            result.append(m * n)
        if result:
            return result
        else:
            return [int(input)]

if __name__ == '__main__':
    input = input()
    solution = Solution()
    print(solution.diffWaysToCompute(input))
