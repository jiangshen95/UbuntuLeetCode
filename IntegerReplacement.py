class Solution:
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 0
        if (n & 1) == 0:
            return 1 + self.integerReplacement(n >> 1)
        else:
            return 2 + min(self.integerReplacement(n >> 1), self.integerReplacement((n >> 1) + 1))


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.integerReplacement(n))
