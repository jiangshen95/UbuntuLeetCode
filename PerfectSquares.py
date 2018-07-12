class Solution:
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        res, num = n, 2
        while num * num <= n:
            a = n // (num * num)
            b = n % (num * num)
            res = min(res, a + self.numSquares(b))
            num += 1
        return res

if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.numSquares(n))
