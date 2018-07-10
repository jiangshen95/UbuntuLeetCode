class Solution:
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        return 0 if num == 0 else 1 + (num - 1) % 9

if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.addDigits(num))
