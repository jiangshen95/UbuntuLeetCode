class Solution:
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 1

        # f(x) = 9 * 9 * 8 * ... * (9 - x + 2)

        s = 10
        d = 9
        for i in range(2, n + 1):
            d *= (11 - i)
            s += d
        return s


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.countNumbersWithUniqueDigits(n))
