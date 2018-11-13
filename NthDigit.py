class Solution:
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        size = 1
        step = 9
        start = 1
        while n > size * step:
            n -= size * step
            size += 1
            step *= 10
            start *= 10
        num = start + (n - 1) / size
        return int(str(num)[(n - 1) % size])


if __name__ == '__main__':
    n = int(input())
    solution = Solution()
    print(solution.findNthDigit(n))
