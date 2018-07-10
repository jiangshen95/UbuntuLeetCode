class Solution:
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        s = 0
        while num // 10 > 0:
            s = 0
            while num > 0:
                s += num % 10
                num //= 10
            num = s
        return num

if __name__ == '__main__':
    num = int(input())
    solution = Solution()
    print(solution.addDigits(num))
