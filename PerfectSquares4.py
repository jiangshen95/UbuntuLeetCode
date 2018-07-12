import math
class Solution:
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        while n % 4 == 0:
            n //= 4
        if n % 8 == 7:
            return 4
        a = 0
        while a * a <= n:
            b = int(math.sqrt(n - a * a))
            if b * b == n - a * a:
                if b == 0 or a == 0:
                    return 1
                else:
                    return 2
            a += 1
        return 3

if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.numSquares(n))
