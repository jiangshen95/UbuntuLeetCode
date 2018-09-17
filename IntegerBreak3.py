class Solution:
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 3:
            return n - 1
        if n == 4:
            return n
        n -= 5
        return int(pow(3, n // 3 + 1) * (n % 3 + 2))


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.integerBreak(n))
