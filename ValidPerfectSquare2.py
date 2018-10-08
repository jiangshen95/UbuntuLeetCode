class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        n = 1
        while n <= num // n:
            if n * n == num:
                return True
            n += 1
        return False


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.isPerfectSquare(num))
