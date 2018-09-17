class Solution:
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return (num > 0) and (num & (num - 1) == 0) and ((num & 0x55555555) != 0)


if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.isPowerOfFour(num))
