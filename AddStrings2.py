class Solution:
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        import itertools, functools
        return str(
            functools.reduce(lambda a, b: a * 10 + b,
                             map(lambda x: ord(x[0]) + ord(x[1]) - 2 * ord('0'),
                                 list(itertools.zip_longest(num1[::-1], num2[::-1], fillvalue='0'))[::-1]))
        )


if __name__ == '__main__':
    num1 = input()
    num2 = input()
    solution = Solution()
    print(solution.addStrings(num1, num2))
