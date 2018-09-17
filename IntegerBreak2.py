class Solution:
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 3:
            return n - 1
        result = 1
        while n > 4:
            result *= 3
            n -= 3
        result *= n
        return result


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.integerBreak(n))
