class Solution:
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        MAX = 0x7FFFFFFF
        MIN = 0x80000000
        mask = 0xFFFFFFFF

        while b != 0:
            a, b = (a ^ b) & mask, ((a & b) << 1) & mask

        return a if a <= MAX else ~(a ^ mask)


if __name__ == '__main__':
    a = int(input())
    b = int(input())
    solution = Solution()
    print(solution.getSum(a, b))
