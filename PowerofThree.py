class Solution:
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n < 1:
            return False
        while n % 3 == 0:
            n /= 3
        return n == 1


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.isPowerOfThree(n))
