import math


class Solution:
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n < 1:
            return False
        t = math.pow(3, int(math.log(2147483647) / math.log(3)))
        return t % n == 0


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.isPowerOfThree(n))
