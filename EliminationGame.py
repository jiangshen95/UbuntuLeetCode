class Solution:
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        def leftToRight(n):
            if n <= 2:
                return n
            return 2 * rightToLeft(n // 2)

        def rightToLeft(n):
            if n <= 2:
                return 1
            if n % 2 == 1:
                return 2 * leftToRight(n // 2)
            else:
                return 2 * leftToRight(n // 2) - 1

        return leftToRight(n)


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.lastRemaining(n))
