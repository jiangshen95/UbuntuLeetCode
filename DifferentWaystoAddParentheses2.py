class Solution:
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        return [a + b if c == '+' else a - b if c == '-' else a * b
                for i, c in enumerate(input) if c in '+-*'
                for a in self.diffWaysToCompute(input[:i])
                for b in self.diffWaysToCompute(input[i + 1:])] or [int(input)]

if __name__ == '__main__':
    input = input()
    solution = Solution()
    print(solution.diffWaysToCompute(input))
