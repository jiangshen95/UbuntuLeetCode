class Solution:
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        nums = []
        ops = []
        where = 0
        for i in range(len(input)):
            if input[i] in '+-*':
                nums.append(int(input[where:i]))
                ops.append(input[i])
                where = i + 1
        nums.append(int(input[where:]))

        dp = [[[] for _ in range(len(nums))] for i in range(len(nums))]
        for i in range(len(nums)):
            dp[i][i].append(nums[i])

        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                for k in range(i, j):
                    num1 = dp[i][k]
                    num2 = dp[k + 1][j]
                    for m in num1:
                        for n in num2:
                            if ops[k] == '+':
                                dp[i][j].append(m + n)
                            elif ops[k] == '-':
                                dp[i][j].append(m - n)
                            elif ops[k] == '*':
                                dp[i][j].append(m * n)
        return dp[0][len(nums) - 1]


if __name__ == '__main__':
    input = input()
    solution = Solution()
    print(solution.diffWaysToCompute(input))
