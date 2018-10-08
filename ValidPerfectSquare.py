class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        n = num
        while n * n > num:
            n >>= 1

        for i in range(n, n * n + 1):
            if i * i == num:
                return True

        return False


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.isPerfectSquare(num))
