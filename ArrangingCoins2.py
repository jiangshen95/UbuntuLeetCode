class Solution:
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        from math import sqrt
        return int((sqrt(8 * n + 1) - 1) / 2)


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.arrangeCoins(n))
