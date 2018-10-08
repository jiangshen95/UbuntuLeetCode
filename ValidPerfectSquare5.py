class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        x = num
        while x * x > num:
            x = (x + num // x) >> 1
        return x * x == num


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.isPerfectSquare(num))
