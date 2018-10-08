class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        n = 1
        while num > 0:
            num -= n
            n += 2
        return num == 0


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.isPerfectSquare(num))
